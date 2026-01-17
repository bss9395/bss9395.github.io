/* UDP_Client.java
Author: BSS9395
Update: 2023-03-20T22:56:00+08@China-Shanghai+08
Design: UDP Client
*/

import java.net.*;

public class UDP_Client {
    static class Send extends Thread {
        public DatagramSocket _client = null;
        public SocketAddress _address = null;
        public Send(DatagramSocket client, SocketAddress server_address) {
            _client = client;
            _address = server_address;
        }

        @Override
        public void run() {
            try {
                byte[] read_buffer = new byte[UDP_Client._udp_buffer_size];
                for(int count = -1; 0 < (count = System.in.read(read_buffer, 0, read_buffer.length)); ) {
                    String read_sink = new String(read_buffer, 0, count);
                    if(1 <= read_sink.length() && read_sink.charAt(read_sink.length() - 1) == '\n') {
                        if(2 <= read_sink.length() && read_sink.charAt(read_sink.length() - 2) == '\r') {
                            read_sink = read_sink.substring(0, read_sink.length() - 2);
                        } else {
                            read_sink = read_sink.substring(0, read_sink.length() - 1);
                        }
                    }
                    byte[] send_buffer = read_sink.getBytes(UDP_Client._encoding_sink);
                    _client.send(new DatagramPacket(send_buffer, send_buffer.length, _address));
                }
            } catch (Exception exception) {
                exception.printStackTrace();
            } finally {
                _client.close();
            }
        }
    }
    static class Recv extends Thread {
        public DatagramSocket _client = null;
        public SocketAddress _address = null;
        public Recv(DatagramSocket client, SocketAddress server_address) {
            _client = client;
            _address = server_address;
        }

        @Override
        public void run() {
            try {
                DatagramPacket recv_packet = new DatagramPacket(new byte[UDP_Client._udp_buffer_size], UDP_Client._udp_buffer_size);
                while(true) {
                    _client.receive(recv_packet);
                    System.out.printf("[%s:%d]%s%n", recv_packet.getAddress().getHostAddress(), recv_packet.getPort(), new String(recv_packet.getData(), 0, recv_packet.getLength(), UDP_Client._encoding_sink));
                }
            } catch(Exception exception) {
                exception.printStackTrace();
            } finally {
                _client.close();
            }
        }
    }

    static public String _server_ipv4 = "localhost";
    static public int _server_port = 30000;
    static public int _udp_buffer_size = 2048;
    static public String _encoding_source  = "GBK";
    static public String _encoding_sink    = "UTF-8";
    static public String _stemp_connecting = "connecting";
    static public String _stemp_connected  = "connected";
    DatagramSocket _client = new DatagramSocket();
    public UDP_Client(String server_ipv4, int server_port)
        throws Exception {
        byte[] send_buffer = UDP_Client._stemp_connecting.getBytes(UDP_Client._encoding_sink);
        _client.send(new DatagramPacket(send_buffer, send_buffer.length, InetAddress.getByName(server_ipv4), server_port));

        DatagramPacket recv_packet = new DatagramPacket(new byte[UDP_Client._udp_buffer_size], UDP_Client._udp_buffer_size);
        _client.receive(recv_packet);
        String recv_stemp = new String(recv_packet.getData(), 0, recv_packet.getLength(), _encoding_sink);
        System.out.printf("[%s:%d]%s%n", recv_packet.getAddress().getHostAddress(), recv_packet.getPort(), recv_stemp);
        if (UDP_Client._stemp_connected.equals(recv_stemp)) {
            send_buffer = UDP_Client._stemp_connected.getBytes(UDP_Client._encoding_sink);
            _client.send(new DatagramPacket(send_buffer, send_buffer.length, recv_packet.getSocketAddress()));

            new Send(_client, recv_packet.getSocketAddress()).start();
            new Recv(_client, recv_packet.getSocketAddress()).start();
        }
    }
    static public void main(String[] argv)
        throws Exception {
        new UDP_Client(UDP_Client._server_ipv4, UDP_Client._server_port);
    }
}
