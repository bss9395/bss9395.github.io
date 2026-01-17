/* TCP_Protocol_Client.java
Author: BSS9395
Update: 2023-03-16T23:04:00+08@China-Shanghai+08
Design: TCP Protocol Client
*/

import java.io.OutputStream;
import java.net.Socket;

public class TCP_Protocol_Client {
    static class Send extends Thread {
        public TCP_Protocol_Client _client = null;
        public Send(TCP_Protocol_Client client) {
            _client = client;
        }

        /*
        case exit:
            exit
        case login:
            #username#password
        case message_peer:
            @peername@message
        case message_group:
            &groupname&message
        */
        @Override
        public void run() {
            try {
                OutputStream output = _client._socket.getOutputStream();
                Byte read_buffer = new Byte(TCP_Protocol._tcp_body_size);
                byte[] send_head = new byte[TCP_Protocol._tcp_head_size];
                byte[] send_body = null;
                while(true) {
                    read_buffer._length = 0;
                    read_buffer._Read_All(System.in);
                    String read_sink = read_buffer._Line_Feed();
                    System.err.println(read_sink);
                    if (read_sink.equals("exit")) {
                        System.out.println("Bye-Bye!");
                        _client._socket.close();
                        System.exit(0);
                    } else if (read_sink.startsWith(TCP_Protocol._sign_login)) {
                        send_body = read_sink.getBytes(TCP_Protocol._encoding_sink);
                        Byte._Bytes_From_Ints(send_head, new int[]{send_body.length, TCP_Protocol._topic_login});
                        output.write(send_head, 0, send_head.length);
                        output.write(send_body, 0, send_body.length);
                        output.flush();
                    } else if(_client._username != null) {
                        if(read_sink.startsWith(TCP_Protocol._sign_peer)) {
                            send_body = (_client._username + read_sink).getBytes(TCP_Protocol._encoding_sink);
                            Byte._Bytes_From_Ints(send_head, new int[]{send_body.length, TCP_Protocol._topic_peer});
                            output.write(send_head, 0, send_head.length);
                            output.write(send_body, 0, send_body.length);
                            output.flush();
                        } else if(read_sink.startsWith(TCP_Protocol._sign_group)) {
                            send_body = (_client._username + read_sink).getBytes(TCP_Protocol._encoding_sink);
                            Byte._Bytes_From_Ints(send_head, new int[]{send_body.length, TCP_Protocol._topic_group});
                            output.write(send_head, 0, send_head.length);
                            output.write(send_body, 0, send_body.length);
                            output.flush();
                        }
                    } else {
                        System.out.println("please login first!");
                    }
                }
            } catch(Exception exception) {
                exception.printStackTrace();
            }
        }
    }
    static class Recv extends Thread {
        public TCP_Protocol_Client _client = null;
        public Recv(TCP_Protocol_Client client) {
            _client = client;
        }

        @Override
        public void run() {
            try {
                TCP_Protocol protocol = new TCP_Protocol();
                while(true) {
                    protocol._Read(_client._socket);
                    String recv_body = new String(protocol._tcp_buffer._data, TCP_Protocol._tcp_head_size, protocol._recv_head[0], TCP_Protocol._encoding_sink);
                    System.err.println(recv_body);
                    if(protocol._recv_head[1] == TCP_Protocol._topic_login) {
                        String[] items = Byte._Split(recv_body, TCP_Protocol._sign_login, 3);
                        if(items[2].equals(TCP_Protocol._stemp_success)) {
                            _client._username = items[1];
                        } else if(items[2].equals(TCP_Protocol._stemp_failed)) {
                            _client._username = null;
                        }
                    } else if(protocol._recv_head[1] == TCP_Protocol._topic_peer) {
                        String[] items = Byte._Split(recv_body, TCP_Protocol._sign_peer, 3);
                        if(items[1].equals(_client._username)) {
                            System.out.printf("%s speaks to you: %s%n", items[0], items[2]);
                        }
                    } else if(protocol._recv_head[1] == TCP_Protocol._topic_group) {
                        String[] items = Byte._Split(recv_body, TCP_Protocol._sign_group, 3);
                        System.out.printf("%s speaks to all: %s%n", items[0], items[2]);
                    }
                }
            } catch(Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    public String _username = "";
    public Socket _socket = null;
    public TCP_Protocol_Client(String server_ipv4, int server_port) {
        try {
            _socket = new Socket(server_ipv4, server_port);
            new Send(this).start();
            new Recv(this).start();
        } catch(Exception exception) {
            exception.printStackTrace();
        }
    }

    static public void main(String[] args) {
        new TCP_Protocol_Client(TCP_Protocol._server_ipv4, TCP_Protocol._server_port);
    }
}
