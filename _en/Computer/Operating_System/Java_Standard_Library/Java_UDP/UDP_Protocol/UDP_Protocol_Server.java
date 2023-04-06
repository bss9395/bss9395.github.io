/* UDP_Protocol_Server.java
Author: BSS9395
Update: 2023-04-06T17:23:00+08@China-Guangdong-Zhanjiang+08
Design: UDP Protocol Server
*/

import java.net.*;
import java.nio.charset.Charset;
import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.util.*;

class Logger {
    static public int _index = 0x00;
    static public int _note  = (_index += 1);
    static public int _debug = (_index += 1);
    static public int _warn  = (_index += 1);
    static public int _error = (_index += 1);
    static public int _fatal = (_index += 1);
    static public String[] _levels = new String[1 + _index];
    static {
        _levels[_note]       = "note ";
        _levels[_debug]      = "debug";
        _levels[_warn]       = "warn ";
        _levels[_error]      = "error";
        _levels[_fatal]      = "fatal";
    }

    static public Logger _udp_server = new Logger("udp_server", Logger._debug);
    static public Logger _udp_client = new Logger("udp_client", Logger._debug);
    public String _instance = "logger";
    public int    _level    = Logger._debug;
    public Logger(String instance, int level) {
        _instance = instance;
        _level    = level;
    }
    public void _Logging(int level, String format, Object ...records) {
        if(_level <= level) {
            StackTraceElement current = Thread.currentThread().getStackTrace()[3];
            if(format == null) {
                System.err.printf("[%s:%s:%s] %s.%s%n", _levels[level], current.getFileName(), current.getLineNumber(), current.getClassName(), current.getMethodName());
            } else {
                System.err.printf("[%s:%s:%s] ", _levels[level], current.getFileName(), current.getLineNumber());
                System.err.printf(format + "%n", records);
            }
        }
    }
    public void _Note (String format, Object ...records) {
        _Logging(_note, format, records);
    }
    public void _Debug(String format, Object ...records) {
        _Logging(_debug, format, records);
    }
    public void _Warn (String format, Object ...records) {
        _Logging(_warn, format, records);
    }
    public void _Error(String format, Object ...records) {
        _Logging(_error, format, records);
    }
    public void _Fatal(String format, Object ...records) {
        _Logging(_fatal, format, records);
    }
}

class Bytes {
    static public void _Shorts_From_Bytes(short[] head, byte[] data, int skip) {
        Logger._udp_server._Note(null);
        for (int i = 0; i < head.length; i += 1) {
            for (int j = 0; j < 2; j += 1) {
                head[i] <<= 8;
                head[i] |= (int) (data[skip + i * 2 + j] & 0x00FF);
            }
        }
    }
    static public void _Ints_From_Bytes(int[] head, byte[] data, int skip) {
        Logger._udp_server._Note(null);
        for (int i = 0; i < head.length; i += 1) {
            head[i] = 0;
            for (int j = 0; j < 4; j += 1) {
                head[i] <<= 8;
                head[i] |= (int) (data[skip + i * 4 + j] & 0x00FF);
            }
        }
    }
    static public String[] _Split(String data, String splitter, int count) {
        Logger._udp_server._Note(null);
        String[] items = new String[count];
        if(data.length() < splitter.length()) {
            return items;
        }
        int index = 0;
        int beg   = splitter.length();
        int end   = -1;
        for( ; index < count - 1; index += 1) {
            end = data.indexOf(splitter, beg);
            if(end < 0) {
                end = data.length();
                items[index] = data.substring(beg, end);
                break;
            }
            items[index] = data.substring(beg, end);
            beg = end + splitter.length();
        }
        if(index == count - 1) {
            items[index] = data.substring(beg, data.length());
        }
        return items;
    }

    public byte[] _data   = null;
    public int    _length = 0;
    public Bytes(int capacity, int skip) {
        Logger._udp_server._Note(null);
        if(skip < 0) {
            skip = 0;
        }
        if(capacity <= 0) {
            capacity = skip + 8;
        }
        _data = new byte[capacity];
        _length = skip;
    }
    public byte[] _Reserve(int remain) {
        Logger._udp_server._Note(null);
        if(_data.length - _length < remain) {
            byte[] buffer = new byte[_length + remain * 2];
            for(int i = 0; i < _length; i += 1) {
                buffer[i] = _data[i];
            }
            _data = buffer;
        }
        return _data;
    }
    public void _Shift(int wipe) {
        Logger._udp_server._Note(null);
        if(wipe <= 0) {
            return;
        } else if(0 < wipe && wipe < _length) {
            for(int beg = 0, size = _length - wipe; beg < size; beg += 1) {
                _data[beg] = _data[wipe + beg];
            }
            _length -= wipe;
        } else if(_length <= wipe) {
            _length = 0;
        }
    }
    public String _Line_Feed(Charset charset) {
        Logger._udp_server._Note(null);
        String content = new String(_data, 0, _length, charset);
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
    public void _Cover(int beg, short[] data) {
        Logger._udp_server._Note(null);
        for(int i = 0; i < data.length; i += 1) {
            short temp = data[i];
            for(int j = 2 - 1; 0 <= j; j -= 1) {
                _data[beg + i * 2 + j] = (byte) temp;
                temp >>= 8;
            }
        }
    }
    public void _Cover(int beg, int[] data) {
        Logger._udp_server._Note(null);
        for(int i = 0; i < data.length; i += 1) {
            int temp = data[i];
            for(int j = 4 - 1; 0 <= j; j -= 1) {
                _data[beg + i * 4 + j] = (byte) temp;
                temp >>= 8;
            }
        }
    }
    public int _Append(String text, Charset charset) {
        Logger._udp_server._Note(null);
        if(text == null) {
            return 0;
        }
        byte[] data = text.getBytes(charset);
        _Reserve(data.length);
        for(int beg = 0; beg < data.length; beg += 1) {
            _data[_length + beg] = data[beg];
        }
        _length += data.length;
        return data.length;
    }
    public int _Append(Bytes data) {
        Logger._udp_server._Note(null);
        if(data == null) {
            return 0;
        }
        _Reserve(data._length);
        for(int beg = 0; beg < data._length; beg += 1) {
            _data[_length + beg] = data._data[beg];
        }
        _length += data._length;
        return data._length;
    }
}

class User {
    public String            _identity    = "";
    public String            _avatar      = "";
    public int               _online      = UDP_Protocol._echo_countdown;
    public InetSocketAddress _address     = null;
    public String            _timestamp   = UDP_Protocol._null_time;
    public String            _history     = "";
    public Bytes             _cached      = null;
    public ChatDialog        _chat_dialog = null;

    @Override
    public String toString() {
        Logger._udp_server._Note(null);
        return String.format("User[identity=%s, avatar=%s, online=%s, address=%s, timestamp=%s, history=%s]", _identity, _avatar, _online, _address, _timestamp, _history);
    }

    public User(String identity, String avatar, int online, InetSocketAddress address, String timestamp) {
        Logger._udp_server._Note(null);
        _identity  = identity;
        _avatar    = avatar;
        _online    = online;
        _address   = address;
        _timestamp = timestamp;
    }
    public User(byte[] data, int[] skip) {
        Logger._udp_server._Note(null);
        short[] head = new short[6];
        Bytes._Shorts_From_Bytes(head, data, skip[0]);
        Logger._udp_server._Warn("User[%s, %s, %s, %s, %s, %s]=%s", head[0], head[1], head[2], head[3], head[4], head[5], new String(data, skip[0] + 6 * 2, head[0] + head[1] + head[2] + head[3] + head[4] + head[5]));
        int beg = skip[0]; int end = beg + 6 * 2;
        beg = end; end = beg + head[0];
        _identity  = new String(data, beg, end - beg, UDP_Protocol._charset_sink);
        beg = end; end = beg + head[1];
        _avatar    = new String(data, beg, end - beg, UDP_Protocol._charset_sink);
        beg = end; end = beg + head[2];
        _online    = Integer.parseInt(new String(data, beg, end - beg, UDP_Protocol._charset_sink));
        beg = end; end = beg + head[3];
        String ip  = new String(data, beg, end - beg, UDP_Protocol._charset_sink);
        beg = end; end = beg + head[4];
        int port   = Integer.parseInt(new String(data, beg, end - beg, UDP_Protocol._charset_sink));
        _address   = new InetSocketAddress(ip, port);
        beg = end; end = beg + head[5];
        _timestamp = new String(data, beg, end - beg, UDP_Protocol._charset_sink);
        skip[0] = end;
    }
    static public ArrayList<User> _Users_From_Byte(int[] head, byte[] data) {
        Logger._udp_server._Debug(null);
        ArrayList<User> users = new ArrayList<User>(10);
        int[] skip = new int[] { UDP_Protocol._udp_head_size };
        while(skip[0] < UDP_Protocol._udp_head_size + head[0]) {
            User user = new User(data, skip);
            Logger._udp_server._Warn("%s", user);
            users.add(user);
        }
        if(skip[0] != UDP_Protocol._udp_head_size + head[0]) {
            Logger._udp_server._Warn("skip[0] != UDP_Protocol._udp_head_size + head[0]");
            users.clear();
        }
        return users;
    }
    public void _Cache() {
        Logger._udp_server._Debug(null);
        Bytes   buffer = new Bytes(128, 6 * 2);
        short[] head   = new short[6];
        head[0] = (short) buffer._Append(_identity, UDP_Protocol._charset_sink);
        head[1] = (short) buffer._Append(_avatar, UDP_Protocol._charset_sink);
        head[2] = (short) buffer._Append(String.valueOf(_online), UDP_Protocol._charset_sink);
        head[3] = (short) buffer._Append(_address.getHostName(), UDP_Protocol._charset_sink);
        head[4] = (short) buffer._Append(String.valueOf(_address.getPort()), UDP_Protocol._charset_sink);
        head[5] = (short) buffer._Append(_timestamp, UDP_Protocol._charset_sink);
        buffer._Cover(0, head);
        _cached = buffer;
    }
}

class UDP_Protocol {
    static public String[] _identities = new String[] {
        "brilliant",
        "bss9395",
        "bss",
        "maker",
        "doggie",
        "piggie",
        "trilobite",
        "limulus",
        "clover",
        "lobster",
        "crab",
        "butterfly",
    };
    static public String[] _avatars = new String[] {
        "Facebook",
        "Line",
        "LinkedIn",
        "Pinterest",
        "QQ",
        "QZone",
        "Sina",
        "Twitter",
        "WeChat"
    };
    static public String[] _greetings = new String[] {
        "Hello!",
        "Hi!",
        "Hello, World!",
        "Nice to meet you!",
        "Long time no see.",
        "How are you?",
        "How have you been?",
        "I am fine.",
        "See you soon.",
        "Bye!",
        "Bye-Bye!",
        "Good Bye!",
        "Have a nice day."
    };

    static public Charset _charset_source    = Charset.defaultCharset();
    static public Charset _charset_sink      = Charset.forName("UTF-8");
    static public ZoneId  _server_zoneID     = ZoneId.of("+08:00");
    static public String  _null_time         = "0001-01-01T01:01:01.000000001+08:00";
    static public String  _multicast_ipv4    = "230.0.0.1";
    static public String  _server_host       = "0.0.0.0";
    static public String  _server_ipv4       = "127.0.0.1";
    static public int     _server_port       = 9395;
    static public int     _server_backlog    = 256;
    static public int     _udp_datagram_size = 65535;
    static public int     _udp_head_size     = 2 * 4;
    static public int     _udp_buffer_init   = 1024;
    static public int     _echo_period       = 1000 * 5;
    static public int     _echo_countdown    = 2;

    static public int _topic         = 0x00;
    static public int _topic_login   = (_topic += 1);
    static public int _topic_logout  = (_topic += 1);
    static public int _topic_echo    = (_topic += 1);
    static public int _topic_user    = (_topic += 1);
    static public int _topic_users   = (_topic += 1);
    static public int _topic_peer    = (_topic += 1);
    static public int _topic_group   = (_topic += 1);
    static public int _topic_history = (_topic += 1);
    static public String[] _topics   = new String[1 + _topic];
    static {
        _topics[_topic_login]        = "topic_login";
        _topics[_topic_logout]       = "topic_logout";
        _topics[_topic_echo]         = "topic_echo";
        _topics[_topic_user]         = "topic_user";
        _topics[_topic_users]        = "topic_users";
        _topics[_topic_peer]         = "topic_peer";
        _topics[_topic_group]        = "topic_group";
        _topics[_topic_history]      = "topic_history";
    }

    static public String _sign_login  = "#";
    static public String _sign_logout = "#";
    static public String _sign_echo   = "#";
    static public String _sign_peer   = "@";
    static public String _sign_group  = "&";
    static public String _stemp_posi  = "posi";
    static public String _stemp_nega  = "nega";
    static public String _stemp_none  = "none";
}

public class UDP_Protocol_Server {
    static class Echo extends Thread {
        public DatagramSocket    _flirter = null;
        public List<User>        _users   = null;
        public Map<String, User> _indexes = null;
        public Echo(DatagramSocket flirter, List<User> users, Map<String, User> indexes) {
            Logger._udp_server._Note(null);
            _flirter = flirter;
            _users   = users;
            _indexes = indexes;

            /* send: */
            Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
            send_buffer._Cover(0, new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_echo });
            Timer timer = new Timer(true);
            timer.schedule(new TimerTask() {
                @Override
                public void run() {
                    try {
                        for (ListIterator<User> iter = _users.listIterator(); iter.hasNext() == true; ) {
                            User user = iter.next();
                            if (user != null) {
                                /*
                                logout : (?, -2]
                                offline: (-2, 0]
                                online : (0, +2]
                                */
                                if(-UDP_Protocol._echo_countdown < user._online) {
                                    _flirter.send(new DatagramPacket(send_buffer._data, 0, send_buffer._length, user._address));
                                    if(user._online == 0) {
                                        _Inform(user);
                                    }
                                    user._online -= 1;
                                }
                            }
                        }
                    } catch (Exception exception) {
                        exception.printStackTrace();
                    }
                }
            }, UDP_Protocol._echo_period, UDP_Protocol._echo_period);
            this.start();
        }
        @Override
        public void run() {
            Logger._udp_server._Note(null);
            try {
                DatagramPacket recv_packet = new DatagramPacket(new byte[UDP_Protocol._udp_buffer_init], UDP_Protocol._udp_buffer_init);
                int[]          recv_head   = new int[2];
                while(true) {
                    _flirter.receive(recv_packet);
                    if (recv_packet.getLength() < UDP_Protocol._udp_head_size) {
                        continue;
                    }
                    Bytes._Ints_From_Bytes(recv_head, recv_packet.getData(), 0);
                    if(recv_packet.getLength() != UDP_Protocol._udp_head_size + recv_head[0]) {
                        Logger._udp_server._Warn("recv_packet.getLength() != UDP_Protocol._udp_head_size + recv_head[0]");
                        continue;
                    }
                    if(recv_head[1] == UDP_Protocol._topic_echo) {
                        /*
                        recv: #user
                        */
                        String   recv_body = new String(recv_packet.getData(), UDP_Protocol._udp_head_size, recv_head[0], UDP_Protocol._charset_sink);
                        String[] items     = Bytes._Split(recv_body, UDP_Protocol._sign_echo, 1);
                        User     user      = _indexes.get(items[0]);
                        if(user != null) {
                            int online = user._online;
                            user._online    = UDP_Protocol._echo_countdown;
                            user._timestamp = ZonedDateTime.now(UDP_Protocol._server_zoneID).toString();
                            if(online <= 0) {
                                _Inform(user);
                            }
                        }
                    }
                }
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }

        public void _Inform(User poster) {
            try {
                /*
                send: #brilliant#online#timestamp
                */
                String send_body  = UDP_Protocol._sign_echo + poster._identity
                                  + UDP_Protocol._sign_echo + String.valueOf(poster._online)
                                  + UDP_Protocol._sign_echo + poster._timestamp;
                Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                send_buffer._Append(send_body, UDP_Protocol._charset_sink);
                send_buffer._Cover(0, new int[]{ send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_echo });
                for (ListIterator<User> iter = _users.listIterator(); iter.hasNext() == true; ) {
                    User user = iter.next();
                    if (user != null && 0 < user._online) {
                        _flirter.send(new DatagramPacket(send_buffer._data, 0, send_buffer._length, user._address));
                    }
                }
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    }
    static class Client extends Thread {
        public List<User>        _users    = null;
        public Map<String, User> _indexes  = null;
        public User              _user     = null;
        public DatagramSocket    _server   = null;
        public Client(List<User> users, Map<String, User> indexes, DatagramSocket server, int[] recv_head, DatagramPacket recv_packet) {
            Logger._udp_server._Debug(null);
            _users   = users;
            _indexes = indexes;
            _server  = server;
            InetSocketAddress client_address = (InetSocketAddress) recv_packet.getSocketAddress();

            try {
                if (recv_head[1] == UDP_Protocol._topic_login) {
                    /*
                    recv: #brilliant#avatar#password
                    send: #nega#brilliant#avatar#timestamp
                    */
                    String   recv_body = new String(recv_packet.getData(), UDP_Protocol._udp_head_size, recv_head[0], UDP_Protocol._charset_sink);
                    Logger._udp_server._Warn("recv_body=%s", recv_body);
                    String[] items     = Bytes._Split(recv_body, UDP_Protocol._sign_login, 3);
                    String   read_body = "";
                    _user = _indexes.get(items[0]);
                    if (_user != null) {
                        if(_user._online <= 0) {  // offline
                            _user._avatar    = items[1];
                            _user._online    = UDP_Protocol._echo_countdown;
                            _user._address   = client_address;
                            _user._timestamp = ZonedDateTime.now(UDP_Protocol._server_zoneID).toString();
                            read_body = UDP_Protocol._sign_login + UDP_Protocol._stemp_nega
                                      + UDP_Protocol._sign_login + _user._identity + UDP_Protocol._sign_login + _user._avatar + UDP_Protocol._sign_login + _user._timestamp;
                            this.start();
                        } else {                  // online
                            read_body = UDP_Protocol._sign_login + UDP_Protocol._stemp_posi
                                      + UDP_Protocol._sign_login + _user._identity + UDP_Protocol._sign_login + _user._avatar + UDP_Protocol._sign_login + _user._timestamp;
                        }
                    } else {                      // nonexist
                        _user = new User(items[0], items[1], UDP_Protocol._echo_countdown, client_address, ZonedDateTime.now(UDP_Protocol._server_zoneID).toString());
                        read_body = UDP_Protocol._sign_login + UDP_Protocol._stemp_none
                                  + UDP_Protocol._sign_login + _user._identity + UDP_Protocol._sign_login + _user._avatar + UDP_Protocol._sign_login + _user._timestamp;
                        this.start();
                    }
                    Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                    send_buffer._Append(read_body, UDP_Protocol._charset_sink);
                    send_buffer._Cover(0, new int[]{ send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_login });
                    _server.send(new DatagramPacket(send_buffer._data, 0, send_buffer._length, client_address));
                } else if (recv_head[1] == UDP_Protocol._topic_logout) {
                    /*
                    recv: #brilliant
                    send: #brilliant#timestamp
                    */
                    String   recv_body = new String(recv_packet.getData(), UDP_Protocol._udp_head_size, recv_head[0], UDP_Protocol._charset_sink);
                    String[] items     = Bytes._Split(recv_body, UDP_Protocol._sign_logout, 1);
                    _user = _indexes.get(items[0]);
                    if (_user != null) {
                        _user._online    = -UDP_Protocol._echo_countdown;
                        _user._timestamp = ZonedDateTime.now(UDP_Protocol._server_zoneID).toString();

                        String send_body = UDP_Protocol._sign_logout + _user._identity
                                         + UDP_Protocol._sign_logout + _user._timestamp;
                        Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                        send_buffer._Append(send_body, UDP_Protocol._charset_sink);
                        int[] send_head = new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_logout };
                        send_buffer._Cover(0, send_head);
                        for(ListIterator<User> iter = _users.listIterator(); iter.hasNext() == true; ) {
                            User user = iter.next();
                            if(_user != user && 0 < user._online) {
                                _server.send(new DatagramPacket(send_buffer._data, 0, send_buffer._length, user._address));
                            }
                        }
                    }
                }
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }

        @Override
        public void run() {
            Logger._udp_server._Debug(null);
            try {
                DatagramSocket client = new DatagramSocket(0, _server.getLocalAddress());
                Logger._udp_server._Warn("client.getLocalSocketAddress()=%s", client.getLocalSocketAddress());

                _users.add(_user);
                _indexes.put(_user._identity, _user);
                Logger._udp_server._Warn("_users.size()=%s", _users.size());
                Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                _user._Cache();
                send_buffer._Append(_user._cached);
                send_buffer._Cover(0, new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_user });

                Bytes send_buffers = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                for(ListIterator<User> iter = _users.listIterator(); iter.hasNext() == true; ) {
                    User user = iter.next();
                    if(_user != user) {
                        user._Cache();
                        send_buffers._Append(user._cached);
                        if(0 < user._online) {
                            client.send(new DatagramPacket(send_buffer._data, 0, send_buffer._length, user._address));
                            Logger._udp_server._Warn("send_buffer._length=%s, user._address=%s", send_buffer._length, user._address);
                        }
                    }
                }
                send_buffers._Cover(0, new int[] { send_buffers._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_users});
                client.send(new DatagramPacket(send_buffers._data, 0, send_buffers._length, _user._address));
                Logger._udp_server._Warn("send_buffers._length=%s, _user._address=%s", send_buffers._length, _user._address);
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    public DatagramSocket    _server  = null;
    public DatagramSocket    _flirter = null;
    public List<User>        _users   = null;
    public Map<String, User> _indexes = null;
    public UDP_Protocol_Server() {
        Logger._udp_server._Note(null);
        try {
            _server  = new DatagramSocket(UDP_Protocol._server_port, InetAddress.getByName(UDP_Protocol._server_host));
            _flirter = new DatagramSocket(0, _server.getLocalAddress());
            _users   = Collections.synchronizedList(new LinkedList<User>());
            _indexes = Collections.synchronizedMap(new TreeMap<String, User>());

            new Echo(_flirter, _users, _indexes);
            while(true) {
                DatagramPacket recv_packet = new DatagramPacket(new byte[UDP_Protocol._udp_buffer_init], UDP_Protocol._udp_buffer_init);
                int[]          recv_head   = new int[UDP_Protocol._udp_head_size / 4];
                _server.receive(recv_packet);
                if(recv_packet.getLength() < UDP_Protocol._udp_head_size) {
                    continue;
                }
                Bytes._Ints_From_Bytes(recv_head, recv_packet.getData(), 0);
                if(recv_packet.getLength() != UDP_Protocol._udp_head_size + recv_head[0]) {
                    Logger._udp_server._Warn("recv_packet.getLength() != UDP_Protocol._udp_head_size + recv_head[0]");
                    continue;
                }
                Logger._udp_server._Warn("[%s] %s", recv_packet.getSocketAddress(), new String(recv_packet.getData(), UDP_Protocol._udp_head_size, recv_head[0], UDP_Protocol._charset_sink));
                new Client(_users, _indexes, _server, recv_head, recv_packet);
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    static public void main(String[] args) {
        Logger._udp_server._level = Logger._debug;
        Logger._udp_client._level = Logger._debug;
        Logger._udp_server._Note(null);
        new UDP_Protocol_Server();
    }
}
