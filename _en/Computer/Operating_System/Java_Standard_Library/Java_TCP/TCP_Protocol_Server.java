/* TCP_Protocol_Server.java
Author: BSS9395
Update: 2023-03-16T23:04:00+08@China-Shanghai+08
Design: TCP Protocol Server
*/

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

class Byte {
    static public void _Ints_From_Bytes(int[] head, byte[] data) {
        for(int i = 0; i < head.length; i += 1) {
            for(int j = 0; j < 4; j += 1) {
                head[i] <<= 8;
                head[i] |= (int)(data[i * 4 + j] & 0xFF);
            }
        }
    }
    static public void _Bytes_From_Ints(byte[] data, int[] head) {
        for(int i = 0; i < head.length; i += 1) {
            for(int j = 4 - 1; 0 <= j; j -= 1) {
                data[i * 4 + j] = (byte)(head[i] & 0xFF);
                head[i] >>= 8;  // should be right-value.
            }
        }
    }
    static public String[] _Split(String content, String delimiter, int count) {
        String[] array = new String[count];
        int beg = 0;
        int end = 0;
        for(int i = 0; i < count; i += 1) {
            end = content.indexOf(delimiter, beg);
            if(end < 0) {
                end = content.length();
            }
            array[i] = content.substring(beg, end);
            beg = end + delimiter.length();
            if(content.length() <= beg) {
                break;
            }
        }
        return array;
    }

    byte[] _data = null;
    int _length = 0;
    public Byte(int capacity) {
        if(capacity <= 0) {
            capacity = 8;
        }
        _data = new byte[capacity];
        _length = 0;
    }
    public byte[] _Reserve(int remain) {
        if(_data.length - _length < remain) {
            byte[] buffer = new byte[_length + remain];
            for(int i = 0; i < _length; i += 1) {
                buffer[i] = _data[i];
            }
            _data = buffer;
        }
        return _data;
    }
    public void _Shift(int wipe) {
        if(wipe <= 0) {
            return;
        } else if(0 < wipe && wipe < _length) {
            for(int beg = 0, size = _length - wipe; beg < size; ) {
                _data[beg] = _data[wipe + beg];
                beg += 1;
            }
            _length -= wipe;
        } else if(_length <= wipe) {
            _length = 0;
        }
    }
    public void _Read_All(InputStream input)
        throws IOException  {
        int count = -1;
        while((count = input.read(_data, _length, _data.length - _length)) == _data.length - _length) {
            _length = _data.length;
            _Reserve(_data.length);
        }
        if(0 < count) {
            _length += count;
        }
    }
    public String _Line_Feed() {
        String content = new String(_data, 0, _length);
        if(1 <= content.length() && content.charAt(content.length() - 1) == '\n') {
            if(2 <= content.length() && content.charAt(content.length() - 2) == '\r') {
                content = content.substring(0, content.length() - 2);
            } else {
                content = content.substring(0, content.length() - 1);
            }
        } else if(1 <= content.length() && content.charAt(content.length() - 1) == '\r') {
            content = content.substring(0, content.length() - 1);
        }
        return content;
    }
}

class PeerException extends Exception {
    public PeerException(String what) {
        super(what);
    }
}

class TCP_Protocol {
    static public String _encoding_source = "GBK";
    static public String _encoding_sink   = "UTF-8";
    static public String _server_ipv4     = "192.168.1.12";
    static public int _server_port        = 30000;
    static public int _server_backlog     = 100;
    static public int _tcp_head_size      = 4 * 2;
    static public int _tcp_body_size      = 2048;

    static public String _sign_login      = "#";
    static public String _sign_peer       = "@";
    static public String _sign_group      = "&";
    static public String _stemp_success   = "success";
    static public String _stemp_failed    = "failed";

    static public int _topic_login        = 0x01;
    static public int _topic_peer         = 0x02;
    static public int _topic_group        = 0x03;


    int[] _recv_head = new int[TCP_Protocol._tcp_head_size / 4];
    Byte _tcp_buffer = new Byte(TCP_Protocol._tcp_body_size * 2);
    public TCP_Protocol() {
        Arrays.fill(_recv_head, 0);
    }
    public void _Read(Socket client)
        throws Exception {
        InputStream input = client.getInputStream();
        _tcp_buffer._Shift(TCP_Protocol._tcp_head_size + _recv_head[0]);
        while(_tcp_buffer._length < TCP_Protocol._tcp_head_size) {
            int count = input.read(_tcp_buffer._Reserve(TCP_Protocol._tcp_body_size), _tcp_buffer._length, TCP_Protocol._tcp_body_size);
            System.err.printf("count = %d%n", count);
            if(count <= 0) {
                throw new PeerException("if(count <= 0) {");
            }
            _tcp_buffer._length += count;
        }
        Byte._Ints_From_Bytes(_recv_head, _tcp_buffer._data);
        while(_tcp_buffer._length < TCP_Protocol._tcp_head_size + _recv_head[0]) {
            int count = input.read(_tcp_buffer._Reserve(TCP_Protocol._tcp_body_size), _tcp_buffer._length, TCP_Protocol._tcp_body_size);
            System.err.printf("count = %d%n", count);
            if(count <= 0) {
                throw new PeerException("if(count <= 0) {");
            }
            _tcp_buffer._length += count;
        }
    }
}

public class TCP_Protocol_Server {
    static class Client extends Thread {
        Map<String, Socket> _clients = null;
        Socket _client = null;
        public Client(Map<String, Socket> clients, Socket client) {
            _clients = clients;
            _client = client;
        }

        @Override
        public void run() {
            try {
                TCP_Protocol protocol = new TCP_Protocol();
                byte[] send_head = new byte[TCP_Protocol._tcp_head_size];
                byte[] send_body = null;
                while(true) {
                    protocol._Read(_client);
                    String recv_body = new String(protocol._tcp_buffer._data, TCP_Protocol._tcp_head_size, protocol._recv_head[0], TCP_Protocol._encoding_sink);
                    System.err.println(protocol._recv_head[1]);
                    System.err.println(recv_body);
                    if(protocol._recv_head[1] == TCP_Protocol._topic_login) {
                        String[] items = Byte._Split(recv_body, TCP_Protocol._sign_login, 3);
                        if(_clients.get(items[1]) == null) {
                            _clients.put(items[1], _client);
                            send_body = (TCP_Protocol._sign_login + items[1] + TCP_Protocol._sign_login + TCP_Protocol._stemp_success).getBytes(TCP_Protocol._encoding_sink);
                        } else {
                            send_body = (TCP_Protocol._sign_login + items[1] + TCP_Protocol._sign_login + TCP_Protocol._stemp_failed).getBytes(TCP_Protocol._encoding_sink);
                        }
                        Byte._Bytes_From_Ints(send_head, new int[] { send_body.length, TCP_Protocol._topic_login});
                        OutputStream output = _client.getOutputStream();
                        output.write(send_head, 0, send_head.length);
                        output.write(send_body, 0, send_body.length);
                        output.flush();
                    } else if(protocol._recv_head[1] == TCP_Protocol._topic_peer) {
                        String[] items = Byte._Split(recv_body, TCP_Protocol._sign_peer, 3);
                        Socket peer = _clients.get(items[1]);
                        if(peer != null) {
                            OutputStream output = peer.getOutputStream();
                            output.write(protocol._tcp_buffer._data, 0, protocol._tcp_buffer._length);
                        } else {
                            System.out.printf("%s not found.%n", items[1]);
                        }
                    } else if(protocol._recv_head[1] == TCP_Protocol._topic_group) {
                        for(Socket client: _clients.values()) {
                            OutputStream output = client.getOutputStream();
                            output.write(protocol._tcp_buffer._data, 0, protocol._tcp_buffer._length);
                        }
                    }
                }
            } catch(Exception exception) {
                exception.printStackTrace();
            } finally {
                try {
                    _client.close();
                    for(Map.Entry<String, Socket> entry : _clients.entrySet()) {
                        if(entry.getValue() == _client) {
                            _clients.remove(entry.getKey());
                            break;
                        }
                    }
                    _clients.remove(_client);
                } catch (Exception exception) {
                    exception.printStackTrace();
                }
            }
        }
    }

    Map<String, Socket> _clients = Collections.synchronizedMap(new TreeMap<String, Socket>());
    public TCP_Protocol_Server(int port, int backlog) {
        try {
            ServerSocket server = new ServerSocket(port, backlog);
            while (true) {
                Socket client = server.accept();
                System.err.println("Socket client = server.accept();");
                new Client(_clients, client).start();
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        } finally {
            try {
                for (Socket client : _clients.values()) {
                    client.close();
                }
                _clients.clear();
            } catch(Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    static public void main(String[] args) {
        new TCP_Protocol_Server(TCP_Protocol._server_port, TCP_Protocol._server_backlog);
    }
}
