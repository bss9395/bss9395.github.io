/* UDP_Protocol_Peer.java
Author: BSS9395
Update: 2023-05-17T13:53:00+08@China-Guangdong-Zhanjiang+08
Design: UDP Protocol Peer
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.font.FontRenderContext;
import java.awt.geom.AffineTransform;
import java.awt.geom.Rectangle2D;
import java.io.IOException;
import java.io.PrintStream;
import java.net.*;
import java.nio.charset.Charset;
import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.util.ArrayList;
import java.util.Random;

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
    static public ArrayList<Logger> _loggers = new ArrayList<Logger>();
    static public Logger            _logger  = Logger._Instance("logger");
    static public Logger _Instance(String instance) {
        for(int i = 0; i < _loggers.size(); i += 1) {
            if(instance.equals(_loggers.get(i)._instance)) {
                return _loggers.get(i);
            }
        }
        Logger logger = new Logger();
        logger._instance = instance;
        _loggers.add(logger);
        return logger;
    }

    ////////////////////////////////////////////////////////////////////////////

    public String      _instance = "logger";
    public int         _level    = Logger._debug;
    public PrintStream _output   = System.err;
    public void _Logging(int level, String format, Object ...records) {
        if(_level <= level) {
            StackTraceElement current = Thread.currentThread().getStackTrace()[3];
            if(format == null) {
                _output.printf("[%s:%s:%s] %s.%s%n", _levels[level], current.getFileName(), current.getLineNumber(), current.getClassName(), current.getMethodName());
            } else {
                _output.printf("[%s:%s:%s] ", _levels[level], current.getFileName(), current.getLineNumber());
                _output.printf(format + "%n", records);
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

class Generator {
    static public Random _random  = new Random(System.currentTimeMillis());
    static public String _charset = "";
    static {
        _charset += "0123456789";
        _charset += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        _charset += "abcdefghijklmnopqrstuvwxyz";
    };
    static public int _Generate_Int(int min, int max) {
        return (min + _random.nextInt(max - min));    // note: max is excluded.
    }
    static public double _Generate_Double(double min, double max) {
        return (min + _random.nextDouble() * (max - min));  // note: max is included.
    }
    static public String _Generate_String(int length) {
        StringBuilder text = new StringBuilder(length);
        for(int i = 0; i < length; i += 1) {
            int index = _random.nextInt(_charset.length());
            text.append(_charset.charAt(index));
        }
        return text.toString();
    }
    static public Color _Generate_RGBA() {
        int red   = _Generate_Int(0, 256);
        int green = _Generate_Int(0, 256);
        int blue  = _Generate_Int(0, 256);
        int alpha = _Generate_Int(128, 256);
        return new Color(red, green, blue, alpha);
    }
}

class Bytes {
    static public void _Shorts_From_Bytes(short[] head, byte[] data, int skip) {
        Logger._logger._Note(null);
        for (int i = 0; i < head.length; i += 1) {
            for (int j = 0; j < 2; j += 1) {
                head[i] <<= 8;
                head[i] |= (int) (data[skip + i * 2 + j] & 0x00FF);
            }
        }
    }
    static public void _Ints_From_Bytes(int[] head, byte[] data, int skip) {
        Logger._logger._Note(null);
        for (int i = 0; i < head.length; i += 1) {
            head[i] = 0;
            for (int j = 0; j < 4; j += 1) {
                head[i] <<= 8;
                head[i] |= (int) (data[skip + i * 4 + j] & 0x00FF);
            }
        }
    }
    static public String[] _Split(String data, String splitter, int count) {
        Logger._logger._Note(null);
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
        Logger._logger._Note(null);
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
        Logger._logger._Note(null);
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
        Logger._logger._Note(null);
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
        Logger._logger._Note(null);
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
        Logger._logger._Note(null);
        for(int i = 0; i < data.length; i += 1) {
            short temp = data[i];
            for(int j = 2 - 1; 0 <= j; j -= 1) {
                _data[beg + i * 2 + j] = (byte) temp;
                temp >>= 8;
            }
        }
    }
    public void _Cover(int beg, int[] data) {
        Logger._logger._Note(null);
        for(int i = 0; i < data.length; i += 1) {
            int temp = data[i];
            for(int j = 4 - 1; 0 <= j; j -= 1) {
                _data[beg + i * 4 + j] = (byte) temp;
                temp >>= 8;
            }
        }
    }
    public int _Append(String text, Charset charset) {
        Logger._logger._Note(null);
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
        Logger._logger._Note(null);
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

class UDP_Protocol {
    static public String[] _identities = new String[] {
            "brilliant",
            "bss9395",
            "bss",
            "maker",
            "doggie",
            "piggie",
            "pigeon",
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
    static public int     _wellknown_port    = 9395;
    static public String  _multicast_ipv4    = "234.1.1.1";
    static public int     _multicast_port    = _wellknown_port + 1;
    static public String  _server_host       = "0.0.0.0";
    static public String  _server_ipv4       = "127.0.0.1";
    static public int     _server_port       = _multicast_port + 1;
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

class User {
    public String            _identity    = "";
    public String            _avatar      = "";
    public int               _online      = UDP_Protocol._echo_countdown;
    public InetSocketAddress _address     = null;
    public String            _timestamp   = UDP_Protocol._null_time;
    public Dialog_Chat       _dialog_chat = null;

    @Override
    public String toString() {
        Logger._logger._Note(null);
        return String.format("User[identity=%s, avatar=%s, online=%s, address=%s, timestamp=%s]", _identity, _avatar, _online, _address, _timestamp);
    }

    public User(String identity, String avatar, int online, InetSocketAddress address, String timestamp) {
        Logger._logger._Note(null);
        _identity  = identity;
        _avatar    = avatar;
        _online    = online;
        _address   = address;
        _timestamp = timestamp;
    }
}

class Dialog_Login extends JDialog {
    public UDP_Protocol_Peer _handler     = null;
    public Dialog_Login      _self        = this;
    public JLabel            _l_info      = new JLabel("");
    public JLabel            _l_avatar    = new JLabel("头像: ");
    public JComboBox<String> _cb_avatars  = new JComboBox<String>(UDP_Protocol._avatars);
    public JLabel            _l_identity  = new JLabel("昵称: ");
    public JTextField        _tf_identity = new JTextField("brilliant");
    public JLabel            _l_password  = new JLabel("密码: ");
    public JTextField        _tf_password = new JTextField("Password");
    public JButton           _b_login     = new JButton("登录");
    public Dialog_Login(UDP_Protocol_Peer handler) {
        super((Dialog) null, "用户登录");
        Logger._logger._Note(null);
        _handler = handler;

        _l_info.setPreferredSize(new Dimension(180, 24));
        _self.add(_l_info, BorderLayout.NORTH);
        Box b_avatar = new Box(BoxLayout.X_AXIS);
        _cb_avatars.setPreferredSize(new Dimension(180, 24));
        b_avatar.add(_l_avatar);
        b_avatar.add(_cb_avatars);
        Box b_identity = new Box(BoxLayout.X_AXIS);
        _tf_identity.setPreferredSize(new Dimension(180, 24));
        b_identity.add(_l_identity);
        b_identity.add(_tf_identity);
        Box b_password = new Box(BoxLayout.X_AXIS);
        _tf_password.setPreferredSize(new Dimension(180, 24));
        b_password.add(_l_password);
        b_password.add(_tf_password);
        Box b_center = new Box(BoxLayout.Y_AXIS);
        b_center.add(b_avatar);
        b_center.add(b_identity);
        b_center.add(b_password);
        _self.add(b_center, BorderLayout.CENTER);
        JPanel p_login = new JPanel();
        p_login.add(_b_login);
        _self.add(p_login, BorderLayout.SOUTH);

        _tf_identity.setText(UDP_Protocol._identities[Generator._Generate_Int(0, UDP_Protocol._identities.length)]);
        _cb_avatars.setSelectedIndex(Generator._Generate_Int(0, _cb_avatars.getModel().getSize()));
        _tf_password.setText(Generator._Generate_String(5));
        _self.pack();

        ////////////////////////////////////////////////////////////////////////

        _self.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                _handler._state = false;
                Logger._logger._Debug("_handler._state=%s", _handler._state);
                _self.dispose();
            }
        });

        _b_login.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                User mine = new User(_tf_identity.getText(), _cb_avatars.getSelectedItem().toString(), UDP_Protocol._echo_countdown, null, ZonedDateTime.now(UDP_Protocol._server_zoneID).toString());
                _handler._dialog_main._Update_Mine(mine);
                _handler._thread_multicast._Echo_User();
                _self.dispose();
            }
        });
    }
}

class Dialog_Chat extends JDialog {
    public Dialog_Chat       _self     = this;
    public UDP_Protocol_Peer _handler  = null;
    public User              _user     = null;
    public JTextArea         _ta_area  = new JTextArea();
    public JTextField        _tf_field = new JTextField(UDP_Protocol._greetings[Generator._Generate_Int(0, UDP_Protocol._greetings.length)]);
    public JButton           _b_send   = new JButton("发送");
    public Dialog_Chat(UDP_Protocol_Peer handler, User user) {
        super((Dialog) null, "");
        Logger._logger._Debug(null);
        _handler = handler;
        _user = user;

        _ta_area.setEditable(false);
        _self.add(new JScrollPane(_ta_area), BorderLayout.CENTER);
        JPanel p_send = new JPanel();
        Box b_field = Box.createHorizontalBox();
        b_field.add(_tf_field);
        b_field.setPreferredSize(new Dimension(250, 25));
        p_send.add(b_field);
        p_send.add(_b_send);
        _self.add(p_send, BorderLayout.SOUTH);
        _self.setPreferredSize(new Dimension(350, 250));
        _self.pack();

        ////////////////////////////////////////////////////////////////////////

        _self.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                _self.setVisible(false);
            }
        });

        AbstractAction send = new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent event) {
                if(_user._identity.equals(_handler._dialog_main._group._identity)) {
                    /*
                    send: &user_send&group_recv&message
                    */
                    String read_body = UDP_Protocol._sign_group + _handler._dialog_main._mine._identity
                                     + UDP_Protocol._sign_group + _user._identity
                                     + UDP_Protocol._sign_group + _tf_field.getText();
                    if(0 < _user._online) {
                        Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                        send_buffer._Append(read_body, UDP_Protocol._charset_sink);
                        int[] send_head = new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_group };
                        send_buffer._Cover(0, send_head);
                        _handler._thread_multicast._Send_Multicast(send_head, new DatagramPacket(send_buffer._data, 0, send_buffer._length, _handler._thread_multicast._multicast_address));
                    }
                    _ta_area.append(read_body + "\n");  // note: multicast loopback.
                    _tf_field.setText(UDP_Protocol._greetings[Generator._Generate_Int(0, UDP_Protocol._greetings.length)]);
                } else {
                    /*
                    send: @user_send@user_recv@message
                    */
                    String read_body = UDP_Protocol._sign_peer + _handler._dialog_main._mine._identity
                                     + UDP_Protocol._sign_peer + _user._identity
                                     + UDP_Protocol._sign_peer + _tf_field.getText();
                    if(0 < _user._online) {
                        Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                        send_buffer._Append(read_body, UDP_Protocol._charset_sink);
                        int[] send_head = new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_peer };
                        send_buffer._Cover(0, send_head);
                        _handler._thread_datagram._Send_Datagram(send_head, new DatagramPacket(send_buffer._data, 0, send_buffer._length, user._address));
                    }
                    _ta_area.append(read_body + "\n");
                    _tf_field.setText(UDP_Protocol._greetings[Generator._Generate_Int(0, UDP_Protocol._greetings.length)]);
                }
            }
        };
        _b_send.addActionListener(send);
        _tf_field.getInputMap().put(KeyStroke.getKeyStroke('\n', InputEvent.CTRL_DOWN_MASK), "Send");
        _tf_field.getActionMap().put("Send", send);
    }
    public void _Recv_Packet(String message) {
        Logger._logger._Debug(null);
        _ta_area.append(message + "\n");
    }
}

class Dialog_Main extends JDialog {
    static class LCR_Panel extends JPanel implements ListCellRenderer<User> {
        public ImageIcon         _icon       = null;
        public User              _user       = null;
        public Color             _background = null;
        public Color             _foreground = null;
        public Font              _font       = new Font("Consola", Font.BOLD, 10);
        public FontRenderContext _context    = new FontRenderContext(new AffineTransform(), true, true);
        @Override
        public Component getListCellRendererComponent(JList<? extends User> list, User user, int index, boolean selected, boolean focus) {
            Logger._logger._Note(null);
            _icon = new ImageIcon(String.format("avatars/%s.svg.png", user._avatar));
            _user = user;
            if(0 < user._online) {
                _background = (selected == true) ? list.getSelectionBackground() : list.getBackground();
            } else {
                _background = Color.gray;
            }
            _foreground = (selected == true) ? list.getSelectionForeground() : list.getForeground();

            if(_user._dialog_chat != null) {
                _user._dialog_chat.setTitle(0 < _user._online ? _user._identity + "在线" : _user._identity + "离线");
            }
            return this;
        }
        public void paintComponent(Graphics graphics) {
            Logger._logger._Note(null);
            int width  = 32;
            int height = 32;
            graphics.setColor(_background);
            graphics.fillRect(0, 0, this.getWidth(), this.getHeight());
            graphics.setColor(_foreground);
            graphics.drawImage(_icon.getImage(), (this.getWidth() - width) / 2, 10, width, height,null);
            graphics.setFont(_font);
            Rectangle2D bounds = _font.getStringBounds(_user._identity, _context);
            graphics.drawString(_user._identity, (int)((this.getWidth() - bounds.getWidth()) / 2), (int)(10 + height + bounds.getHeight()));
        }
        public Dimension getPreferredSize() {
            Logger._logger._Note(null);
            return new Dimension(80, 60);
        }
    }

    public Dialog_Main            _self      = this;
    public UDP_Protocol_Peer      _handler   = null;
    public User                   _group     = new User("Group", "Facebook", UDP_Protocol._echo_countdown, null, ZonedDateTime.now(UDP_Protocol._server_zoneID).toString());
    public User                   _mine      = new User("Mine" , "Facebook", UDP_Protocol._echo_countdown, null, ZonedDateTime.now(UDP_Protocol._server_zoneID).toString());
    public DefaultListModel<User> _dlm_users = new DefaultListModel<User>();
    public JList<User>            _l_users   = new JList<User>(_dlm_users);
    public Dialog_Main(UDP_Protocol_Peer handler) {
        super((JDialog) null, "控制面板");
        Logger._logger._Debug(null);
        _handler = handler;

        _dlm_users.addElement(_group);
        _self.add(new JScrollPane(_l_users));
        _self.setPreferredSize(new Dimension(250, 500));
        _self.pack();

        ////////////////////////////////////////////////////////////////////////

        _self.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                _handler._state = false;
                Logger._logger._Debug("_handler._state=%s", _handler._state);
                _self.dispose();
            }
        });

        _l_users.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent event) {
                if(2 <= event.getClickCount()) {
                    User user = (User) _l_users.getSelectedValue();
                    if(user != null) {
                        if(user._dialog_chat == null) {
                            user._dialog_chat = new Dialog_Chat(_handler, user);
                            user._dialog_chat.setModal(false);
                        }
                        if(user._dialog_chat.isVisible() == false) {
                            user._dialog_chat.setVisible(true);
                        }
                    }
                }
            }
        });
        _l_users.setCellRenderer(new LCR_Panel());
    }
    public void _Update_Mine(User mine) {
        _mine = mine;
        this.setTitle(String.format("%s:%s", _mine._identity, _mine._avatar));
    }
    public void _Recv_Packet(int[] head, DatagramPacket packet) {
        Logger._logger._Debug(null);
        if(head[1] == UDP_Protocol._topic_user) {
            /*
            recv: #identity#avatar
            */
            String            recv_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
            String[]          items     = Bytes._Split(recv_body, UDP_Protocol._sign_login, 2);
            InetSocketAddress address   = new InetSocketAddress(packet.getAddress(), UDP_Protocol._wellknown_port);
            User              fresh     = new User(items[0], items[1], UDP_Protocol._echo_countdown, address, ZonedDateTime.now(UDP_Protocol._server_zoneID).toString());
            Logger._logger._Warn("Dialog_Main._Recv_Packet(): [%s] fresh._identity=%s, _mine._identity=%s", address, fresh._identity, _mine._identity);
            if(fresh._identity.equals(_mine._identity) == true) {
                Logger._logger._Warn("\nfresh._identity.equals(_mine._identity) == true");
                _mine._avatar = fresh._avatar;
                _mine._online = fresh._online;
                _mine._timestamp = fresh._timestamp;
            } else {
                User  user  = _Get_User(items[0]);
                if(user != null) {
                    user._avatar = fresh._avatar;
                    user._online = fresh._online;
                    user._timestamp = fresh._timestamp;
                } else {
                    _dlm_users.addElement(fresh);
                }
            }
        } else if(head[1] == UDP_Protocol._topic_peer) {
            /*
            recv: @user_send@user_recv@message
            */
            String   recv_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
            String[] items     = Bytes._Split(recv_body, UDP_Protocol._sign_peer, 3);
            User     user      = _Get_User(items[0]);
            if(user != null) {
                if(user._dialog_chat == null) {
                    user._dialog_chat = new Dialog_Chat(_handler, user);
                    user._dialog_chat.setModal(false);
                }
                user._dialog_chat._Recv_Packet(recv_body);
            }
        } else if(head[1] == UDP_Protocol._topic_group) {
            /*
            recv: &user_send&group_recv&message
            */
            String   recv_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
            String[] items     = Bytes._Split(recv_body, UDP_Protocol._sign_group, 3);
            if(items[0].equals(_mine._identity) == false && items[1].equals(_group._identity) == true) {
                if(_group._dialog_chat == null) {
                    _group._dialog_chat = new Dialog_Chat(_handler, _group);
                    _group._dialog_chat.setModal(false);
                }
                _group._dialog_chat._Recv_Packet(recv_body);
            }
        }
    }
    public User _Get_User(String identity) {
        Logger._logger._Note(null);
        for(int i = 0; i < _dlm_users.size(); i += 1) {
            User user = _dlm_users.get(i);
            if(user != null && identity.equals(user._identity) == true) {
                return user;
            }
        }
        return null;
    }
}

public class UDP_Protocol_Peer {
    static class Thread_Multicast extends Thread {
        public UDP_Protocol_Peer _handler           = null;
        public InetSocketAddress _multicast_address = new InetSocketAddress(UDP_Protocol._multicast_ipv4, UDP_Protocol._multicast_port);
        public MulticastSocket   _multicast         = new MulticastSocket(_multicast_address.getPort());
        public Thread_Multicast(UDP_Protocol_Peer handler) throws IOException {
            Logger._logger._Debug(null);
            _handler = handler;
            _multicast.joinGroup(_multicast_address.getAddress());
            // _multicast.setLoopbackMode(false);  // note: enable loopback
            _multicast.setLoopbackMode(true);   // note: disable loopback
            _multicast.setTimeToLive(255);
        }
        @Override
        public void run() {
            Logger._logger._Debug(null);
            try {
                while(_handler._state == true) {
                    int[]          recv_head   = new int[UDP_Protocol._udp_head_size / 4];
                    DatagramPacket recv_packet = new DatagramPacket(new byte[UDP_Protocol._udp_buffer_init], UDP_Protocol._udp_buffer_init);
                    _multicast.receive(recv_packet);
                    if(recv_packet.getLength() < UDP_Protocol._udp_head_size) {
                        continue;
                    }
                    Bytes._Ints_From_Bytes(recv_head, recv_packet.getData(), 0);
                    if(recv_packet.getLength() != UDP_Protocol._udp_head_size + recv_head[0]) {
                        Logger._logger._Warn("recv_packet.getLength() != UDP_Protocol._udp_head_size + recv_head[0]");
                        continue;
                    }
                    Logger._logger._Warn("Thread_Multicast.run(): [%s, %s|%s] %s", recv_packet.getSocketAddress().toString(), recv_head[0], UDP_Protocol._topics[recv_head[1]], new String(recv_packet.getData(), UDP_Protocol._udp_head_size, recv_head[0], UDP_Protocol._charset_sink));
                    if(recv_head[1] == UDP_Protocol._topic_user) {
                        _handler._dialog_main._Recv_Packet(recv_head, recv_packet);
                    } else if(recv_head[1] == UDP_Protocol._topic_group){
                        _handler._dialog_main._Recv_Packet(recv_head, recv_packet);
                    }

                }
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
        public void _Send_Multicast(int[] head, DatagramPacket packet) {
            Logger._logger._Debug(null);
            try {
                String send_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
                Logger._logger._Warn("Thread_Multicast._Send_Multicast(): [%s, %s|%s] %s", packet.getSocketAddress(), head[0], UDP_Protocol._topics[head[1]], send_body);
                _multicast.send(packet);
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
        public void _Echo_User() {
            Logger._logger._Debug(null);
            /*
            send: #identity#avatar
            */
            Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
            String read_body  = UDP_Protocol._sign_login + _handler._dialog_main._mine._identity
                              + UDP_Protocol._sign_login + _handler._dialog_main._mine._avatar;
            send_buffer._Append(read_body, UDP_Protocol._charset_sink);
            int[] send_head   = new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_user };
            send_buffer._Cover(0, send_head);
            _Send_Multicast(send_head, new DatagramPacket(send_buffer._data, 0, send_buffer._length, _multicast_address));

            Timer timer = new Timer(UDP_Protocol._echo_period, new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent event) {
                    _Send_Multicast(send_head, new DatagramPacket(send_buffer._data, 0, send_buffer._length, _multicast_address));
                    for(int i = 0; i < _handler._dialog_main._dlm_users.size();) {
                        User user = _handler._dialog_main._dlm_users.get(i);
                        if(user._identity.equals(_handler._dialog_main._group._identity)) {
                            i += 1;
                        } else if(user._identity.equals(_handler._dialog_main._mine._identity)) {
                            i += 1;
                        } else if(-UDP_Protocol._echo_countdown < user._online) {
                            user._online -= 1;
                            i += 1;
                        } else {
                            _handler._dialog_main._dlm_users.remove(i);
                        }
                    }
                    _handler._dialog_main.repaint();
                }
            });
            timer.setInitialDelay(UDP_Protocol._echo_period);
            timer.start();
        }
    }
    static class Thread_Datagram extends Thread {
        public UDP_Protocol_Peer _handler  = null;
        public DatagramSocket    _datagram = new DatagramSocket(UDP_Protocol._wellknown_port);
        public Thread_Datagram(UDP_Protocol_Peer handler) throws SocketException {
            Logger._logger._Debug(null);
            _handler = handler;
        }
        @Override
        public void run() {
            Logger._logger._Debug(null);
            try {
                while(_handler._state == true) {
                    int[]          recv_head   = new int[UDP_Protocol._udp_head_size / 4];
                    DatagramPacket recv_packet = new DatagramPacket(new byte[UDP_Protocol._udp_buffer_init], UDP_Protocol._udp_buffer_init);
                    _datagram.receive(recv_packet);
                    if(recv_packet.getLength() < UDP_Protocol._udp_head_size) {
                        continue;
                    }
                    Bytes._Ints_From_Bytes(recv_head, recv_packet.getData(), 0);
                    if(recv_packet.getLength() != UDP_Protocol._udp_head_size + recv_head[0]) {
                        Logger._logger._Warn("recv_packet.getLength() != UDP_Protocol._udp_head_size + recv_head[0]");
                        continue;
                    }
                    Logger._logger._Warn("Thread_Datagram.run(): [%s, %s|%s] %s", recv_packet.getSocketAddress().toString(), recv_head[0], UDP_Protocol._topics[recv_head[1]], new String(recv_packet.getData(), UDP_Protocol._udp_head_size, recv_head[0], UDP_Protocol._charset_sink));
                    if(recv_head[1] == UDP_Protocol._topic_peer) {
                        _handler._dialog_main._Recv_Packet(recv_head, recv_packet);
                    }
                }
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
        public void _Send_Datagram(int[] head, DatagramPacket packet) {
            Logger._logger._Debug(null);
            try {
                String send_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
                Logger._logger._Warn("Thread_Datagram._Send_Datagram(): [%s, %s|%s] %s", packet.getSocketAddress(), head[0], UDP_Protocol._topics[head[1]], send_body);
                _datagram.send(packet);
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    public boolean           _state             = true;
    public Thread_Multicast  _thread_multicast  = null;
    public Thread_Datagram   _thread_datagram   = null;
    public Dialog_Login      _dialog_login      = null;
    public Dialog_Main       _dialog_main       = null;
    public UDP_Protocol_Peer() {
        Logger._logger._Debug(null);
        try {
            _thread_multicast = new Thread_Multicast(this);
            _thread_datagram  = new Thread_Datagram(this);
            _dialog_main      = new Dialog_Main(this);
            _dialog_login     = new Dialog_Login(this);
            _thread_multicast.start();
            _thread_datagram.start();
            _dialog_login.setModal(true);
            _dialog_login.setVisible(true);
            if(_state == true) {
                _dialog_main.setModal(false);
                _dialog_main.setVisible(true);
            } else {
                _dialog_main.dispose();
            }
            Logger._logger._Debug("at the end.");
            while(_state == true);
        } catch (Exception exception) {
            exception.printStackTrace();
        } finally {
            _Cleanup();
        }
    }
    public void _Cleanup() {
        Logger._logger._Debug(null);
        try {
            if(_thread_multicast != null) {
                _thread_multicast._multicast.leaveGroup(_thread_multicast._multicast_address.getAddress());
                _thread_multicast._multicast.close();
            }
            if(_thread_datagram != null) {
                _thread_datagram._datagram.close();
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    static public void main(String[] args) {
        Logger._logger._Debug(null);
        new UDP_Protocol_Peer();
    }
}