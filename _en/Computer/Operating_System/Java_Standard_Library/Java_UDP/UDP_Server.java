/* UDP_Server.java
Author: BSS9395
Update: 2023-03-20T22:56:00+08@China-Shanghai+08
Design: UDP Server
*/

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.*;

public class UDP_Server {
    static class UDP_Socket {
        static DatagramPacket _recv_packet = new DatagramPacket(new byte[128], 128);
        static public int _socket_port_init = 1234;
        static public int _socket_port = _socket_port_init;
        static public String _encoding_sink = "UTF-8";
        static String _stemp_connecting = "connecting";
        static String _stemp_connected  = "connected";
        static public Map<String, DatagramSocket> _clients = Collections.synchronizedMap(new TreeMap<String, DatagramSocket>());

        static public DatagramSocket _Accept(DatagramSocket server)
            throws IOException {
            while(true) {
                server.receive(_recv_packet);
                String recv_stemp = new String(_recv_packet.getData(), 0, _recv_packet.getLength(), _encoding_sink);
                System.out.printf("[%s]%s%n", _recv_packet.getSocketAddress(), recv_stemp);
                if(_stemp_connecting.equals(recv_stemp)) {
                    DatagramSocket client = new DatagramSocket();
                    System.out.printf("[%s:%d]%n", client.getInetAddress(), client.getPort());
                    _clients.put(_recv_packet.getSocketAddress().toString(), client);
                    byte[] send_body = _stemp_connected.getBytes(_encoding_sink);
                    client.send(new DatagramPacket(send_body, send_body.length, _recv_packet.getSocketAddress()));

                    client.receive(_recv_packet);
                    recv_stemp = new String(_recv_packet.getData(), 0, _recv_packet.getLength(), _encoding_sink);
                    System.out.printf("[%s]%s%n", _recv_packet.getSocketAddress(), recv_stemp);
                    if (_stemp_connected.equals(recv_stemp)) {
                        client = _clients.get(_recv_packet.getSocketAddress().toString());
                        if (client != null) {
                            _clients.remove(_recv_packet.getSocketAddress().toString());
                            return client;
                        }
                    }
                }
            }
        }
    }

    static class Client extends Thread {
        public Map<String, DatagramSocket> _clients = null;
        public DatagramSocket _client = null;
        public Client(Map<String, DatagramSocket> clients, DatagramSocket client) {
            _clients = clients;
            _client = client;
        }
        @Override
        public void run() {
            try {
                DatagramPacket packet = new DatagramPacket(new byte[UDP_Server._udp_buffer_size], UDP_Server._udp_buffer_size);
                while (true) {
                    _client.receive(packet);
                    System.out.printf("[%s]%s%n", packet.getSocketAddress(), new String(packet.getData(), 0, packet.getLength(), UDP_Server._encoding_sink));
                    _client.send(packet);
                }
            } catch(Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    static public String _encoding_source = "GBK";
    static public String _encoding_sink   = "UTF-8";
    static public String _server_ipv4 = "0.0.0.0";
    static public int _server_port = 30000;
    static public int _udp_buffer_size = 2048;
    DatagramSocket _server = null;
    public Map<String, DatagramSocket> _clients = Collections.synchronizedMap(new TreeMap<String, DatagramSocket>());
    public UDP_Server(String ipv4, int port) {
        try {
            _server = new DatagramSocket(port, InetAddress.getByName(ipv4));
            while(true) {
                DatagramSocket client = UDP_Socket._Accept(_server);
                System.out.printf("[%s:%d]%n", client.getInetAddress(), client.getPort());
                new Client(_clients, client).start();
            }
        } catch(Exception exception) {
            exception.printStackTrace();
        } finally {
            for(DatagramSocket client: _clients.values()) {
                client.close();
            }
            _clients.clear();
            _server.close();
        }
    }

    static public void main(String[] argv) {
        new UDP_Server(UDP_Server._server_ipv4, UDP_Server._server_port);
    }
}
