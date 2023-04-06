/* UDP_Multicast.java
Author: BSS9395
Update: 2023-03-22T19:46:00+08@China-Shanghai+08
Design: UDP Multicast
*/

import java.io.IOException;
import java.net.*;

public class UDP_Multicast {
    static class Send extends Thread {
        public MulticastSocket _peer = null;
        public InetSocketAddress _address = null;
        public Send(MulticastSocket peer, InetSocketAddress address) {
            _peer = peer;
            _address = address;
        }

        @Override
        public void run() {
            try {
                byte[] read_buffer = new byte[UDP_Multicast._multicast_buffer_size];
                for (int count = -1; 0 < (count = System.in.read(read_buffer)); ) {
                    String read_sink = new String(read_buffer, 0, count);
                    if(1 <= read_sink.length() && read_sink.charAt(read_sink.length() - 1) == '\n') {
                        if(2 <= read_sink.length() && read_sink.charAt(read_sink.length() - 2) == '\r') {
                            read_sink = read_sink.substring(0, read_sink.length() - 2);
                        } else {
                            read_sink = read_sink.substring(0, read_sink.length() - 1);
                        }
                    }
                    byte[] send_packet = read_sink.getBytes(UDP_Multicast._encoding_sink);
                    _peer.send(new DatagramPacket(send_packet, send_packet.length, _address));
                }
            } catch(Exception exception) {
                exception.printStackTrace();
            } finally {
                try {
                    _peer.leaveGroup(_address.getAddress());
                } catch (IOException e) {
                    e.printStackTrace();
                } finally {
                    _peer.close();
                }
            }
        }
    }
    static class Recv extends Thread {
        public MulticastSocket _peer = null;
        public InetSocketAddress _address = null;
        public Recv(MulticastSocket peer, InetSocketAddress address) {
            _peer = peer;
            _address = address;
        }

        @Override
        public void run() {
            try {
                DatagramPacket recv_packet = new DatagramPacket(new byte[UDP_Multicast._multicast_buffer_size], UDP_Multicast._multicast_buffer_size);
                while (true) {
                    _peer.receive(recv_packet);
                    String recv_sink = new String(recv_packet.getData(), 0, recv_packet.getLength(), UDP_Multicast._encoding_sink);
                    System.out.println(recv_sink);
                }
            } catch (Exception exception) {
                exception.printStackTrace();
            } finally {
                try {
                    _peer.leaveGroup(_address.getAddress());
                } catch (Exception exception) {
                    exception.printStackTrace();
                } finally {
                    _peer.close();
                }
            }
        }
    }

    static public String _multicast_ipv4 = "230.0.0.1";
    static public int _multicast_port = 30000;
    static public int _multicast_buffer_size = 2048;
    static public String _encoding_source = "GBK";
    static public String _encoding_sink = "UTF-8";

    public MulticastSocket _peer = null;
    public InetSocketAddress _address = null;
    public UDP_Multicast(String multicast_ipv4, int multicast_port)
        throws IOException {
        _address = new InetSocketAddress(multicast_ipv4, multicast_port);
        _peer = new MulticastSocket(_address.getPort());
        _peer.joinGroup(_address.getAddress());
        _peer.setLoopbackMode(true);
        _peer.setTimeToLive(255);
        new Send(_peer, _address).start();
        new Recv(_peer, _address).start();
    }
    static public void main(String[] argv)
        throws IOException {
        new UDP_Multicast(UDP_Multicast._multicast_ipv4, UDP_Multicast._multicast_port);
    }
}
