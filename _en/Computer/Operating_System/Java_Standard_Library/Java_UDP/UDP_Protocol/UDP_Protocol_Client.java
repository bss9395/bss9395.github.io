/* UDP_Protocol_Client.java
Author: BSS9395
Update: 2023-04-06T17:23:00+08@China-Guangdong-Zhanjiang+08
Design: UDP Protocol Client
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.font.FontRenderContext;
import java.awt.geom.AffineTransform;
import java.awt.geom.Rectangle2D;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;
import java.time.ZonedDateTime;
import java.util.ArrayList;
import java.util.Random;

class Generation {
    static Random _random = new Random(System.currentTimeMillis());
    static public String _charset = "";
    static {
        _charset += "0123456789";
        _charset += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        _charset += "abcdefghijklmnopqrstuvwxyz";
    };
    static public String _Generate_String(int length) {
        Logger._udp_client._Note(null);
        StringBuilder data = new StringBuilder(length);
        for(int i = 0; i < length; i += 1) {
            int index = _random.nextInt(_charset.length());
            data.append(_charset.charAt(index));
        }
        return data.toString();
    }
    static public int _Generate_Int(int min, int max) {
        Logger._udp_client._Note(null);
        int data = min + _random.nextInt(max - min);
        return data;
    }
}

class LoginDialog extends JDialog {
    public UDP_Protocol_Client _handler     = null;
    public JLabel              _l_info      = new JLabel("");
    public JLabel              _l_avatar    = new JLabel("头像: ");
    public JComboBox<String>   _cb_avatars  = new JComboBox<String>(UDP_Protocol._avatars);
    public JLabel              _l_identity  = new JLabel("昵称: ");
    public JTextField          _tf_identity = new JTextField("brilliant");
    public JLabel              _l_password  = new JLabel("密码: ");
    public JTextField          _tf_password = new JTextField("Password");
    public JButton             _b_login     = new JButton("登录");
    public LoginDialog(UDP_Protocol_Client handler) {
        super((Dialog) null, "用户登录");
        Logger._udp_client._Note(null);
        _handler = handler;

        _tf_identity.setText(UDP_Protocol._identities[Generation._Generate_Int(0, UDP_Protocol._identities.length)]);
        _cb_avatars.setSelectedIndex(Generation._Generate_Int(0, _cb_avatars.getModel().getSize()));
        _tf_password.setText(Generation._Generate_String(5));

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                System.exit(0);
            }
        });

        _b_login.addActionListener((event) -> {
            Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
            String read_body  = UDP_Protocol._sign_login + _tf_identity.getText()
                              + UDP_Protocol._sign_login + _cb_avatars.getSelectedItem().toString()
                              + UDP_Protocol._sign_login + _tf_password.getText();
            send_buffer._Append(read_body, UDP_Protocol._charset_sink);
            int[] send_head   = new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_login };
            send_buffer._Cover(0, send_head);
            _handler._Send_Packet(send_head, new DatagramPacket(send_buffer._data, 0, send_buffer._length, _handler._server_address));
        });

        Box b_info = new Box(BoxLayout.X_AXIS);
        _l_info.setPreferredSize(new Dimension(180, 24));
        b_info.add(_l_info);
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
        Box b_login = new Box(BoxLayout.X_AXIS);
        b_login.add(_b_login);
        Box b_center = new Box(BoxLayout.Y_AXIS);
        b_center.add(b_info);
        b_center.add(b_avatar);
        b_center.add(b_identity);
        b_center.add(b_password);
        b_center.add(b_login);
        b_center.add(new JPanel());
        this.add(b_center);
        this.pack();
    }
    public void _Recv_Packet(int[] head, DatagramPacket packet) {
        Logger._udp_client._Debug(null);
        try {
            if(head[1] == UDP_Protocol._topic_login) {
                /*
                recv: #nega#brilliant#avatar#timestamp
                */
                String recv_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
                _l_info.setText(recv_body);
                String[] items = Bytes._Split(recv_body, UDP_Protocol._sign_login, 4);
                if(items[0].equals(UDP_Protocol._stemp_posi) == false) {
                    _handler._main_dialog._self = new User(items[1], items[2], UDP_Protocol._echo_countdown, (InetSocketAddress) _handler._client.getLocalSocketAddress(), items[3]);
                    _handler._main_dialog.setTitle(String.format("%s [%s]", _handler._main_dialog._self._identity, _handler._main_dialog._self._address));
                    this.dispose();
                }
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
}

class ChatDialog extends JDialog {
    public UDP_Protocol_Client _handler  = null;
    public User                _user     = null;
    public JTextArea           _ta_area  = new JTextArea("");
    public JTextField          _tf_field = new JTextField("Hello, World!");
    public JButton             _b_send   = new JButton("发送");
    public ChatDialog(UDP_Protocol_Client handler, User user) {
        super((Dialog) null, "");
        Logger._udp_client._Debug(null);
        _handler = handler;
        _user = user;
        this.setTitle(0 < _user._online ? _user._identity + "在线" : _user._identity + "离线");

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                ChatDialog dialog = (ChatDialog) event.getComponent();
                dialog.setVisible(false);
            }
        });

        AbstractAction send = new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent event) {
                if(_user._identity.equals(_handler._main_dialog._group._identity)) {
                    String read_body = UDP_Protocol._sign_group + _handler._main_dialog._self._identity
                                     + UDP_Protocol._sign_group + _user._identity
                                     + UDP_Protocol._sign_group + _tf_field.getText();
                    if(0 < _user._online) {
                        Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                        send_buffer._Append(read_body, UDP_Protocol._charset_sink);
                        int[] send_head = new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_group };
                        send_buffer._Cover(0, send_head);
                        for(int i = 0; i < _handler._main_dialog._dlm_users.size(); i += 1) {
                            User user = _handler._main_dialog._dlm_users.get(i);
                            if(user != null && 0 < user._online) {
                                _handler._Send_Packet(send_head, new DatagramPacket(send_buffer._data, 0, send_buffer._length, user._address));
                            }
                        }
                    }
                    _ta_area.append(read_body + "\n");
                    _tf_field.setText(UDP_Protocol._greetings[Generation._Generate_Int(0, UDP_Protocol._greetings.length)]);
                } else {
                    String read_body = UDP_Protocol._sign_peer + _handler._main_dialog._self._identity
                                     + UDP_Protocol._sign_peer + _user._identity
                                     + UDP_Protocol._sign_peer + _tf_field.getText();
                    if(0 < _user._online) {
                        Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                        send_buffer._Append(read_body, UDP_Protocol._charset_sink);
                        int[] send_head = new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_peer };
                        send_buffer._Cover(0, send_head);
                        _handler._Send_Packet(send_head, new DatagramPacket(send_buffer._data, 0, send_buffer._length, user._address));
                    }
                    _ta_area.append(read_body + "\n");
                    _tf_field.setText(UDP_Protocol._greetings[Generation._Generate_Int(0, UDP_Protocol._greetings.length)]);
                }
            }
        };
        _b_send.addActionListener(send);
        _tf_field.getInputMap().put(KeyStroke.getKeyStroke('\n', InputEvent.CTRL_DOWN_MASK), "Send");
        _tf_field.getActionMap().put("Send", send);

        Box b_center = new Box(BoxLayout.Y_AXIS);
        _ta_area.setEditable(false);
        _ta_area.setPreferredSize(new Dimension(400, 200));
        b_center.add(new JScrollPane(_ta_area));
        Box b_send = new Box(BoxLayout.X_AXIS);
        _tf_field.setPreferredSize(new Dimension(300, 24));
        b_send.add(_tf_field);
        b_send.add(_b_send);
        b_center.add(b_send);
        this.add(b_center);
        this.pack();
    }
    public void _Recv_Packet(String message) {
        Logger._udp_client._Debug(null);
        _ta_area.append(message + "\n");
    }
}

class MainDialog extends JDialog {
    static class LCR_Panel extends JPanel implements ListCellRenderer<User> {
        public ImageIcon         _icon       = null;
        public User              _user       = null;
        public Color             _background = null;
        public Color             _foreground = null;
        public Font              _font       = new Font("Consola", Font.BOLD, 10);
        public FontRenderContext _context    = new FontRenderContext(new AffineTransform(), true, true);
        @Override
        public Component getListCellRendererComponent(JList<? extends User> list, User user, int index, boolean selected, boolean focus) {
            Logger._udp_client._Note(null);
            _icon       = new ImageIcon("avatars/" + user._avatar + ".svg.png");
            _user       = user;
            if(0 < user._online) {
                _background = (selected == true) ? list.getSelectionBackground() : list.getBackground();
            } else {
                _background = Color.gray;
            }
            _foreground = (selected == true) ? list.getSelectionForeground() : list.getForeground();
            return this;
        }
        public void paintComponent(Graphics graphics) {
            Logger._udp_client._Note(null);
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
            Logger._udp_client._Note(null);
            return new Dimension(80, 60);
        }
    }

    public UDP_Protocol_Client    _handler   = null;
    public User                   _self      = null;
    public User                   _group     = null;
    public DefaultListModel<User> _dlm_users = new DefaultListModel<User>();
    public JList<User>            _l_users   = new JList<User>(_dlm_users);
    public MainDialog(UDP_Protocol_Client handler) {
        super((JDialog) null, "控制面板");
        Logger._udp_client._Debug(null);
        _handler = handler;

        _group = new User("All", "Facebook", UDP_Protocol._echo_countdown, null, ZonedDateTime.now(UDP_Protocol._server_zoneID).toString());
        _dlm_users.addElement(_group);

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                /*
                send: #brilliant
                */
                MainDialog dialog      = (MainDialog) event.getComponent();
                Bytes      send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                String     send_body   = UDP_Protocol._sign_logout + dialog._self._identity;
                send_buffer._Append(send_body, UDP_Protocol._charset_sink);
                int[]      send_head   = new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_logout };
                send_buffer._Cover(0, send_head);
                dialog._handler._Send_Packet(send_head, new DatagramPacket(send_buffer._data, 0, send_buffer._length, dialog._handler._server_address));
                System.exit(0);
            }
        });

        _l_users.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent event) {
                if(2 <= event.getClickCount()) {
                    User user = (User) _l_users.getSelectedValue();
                    if(user != null) {
                        if(user._chat_dialog == null) {
                            user._chat_dialog = new ChatDialog(_handler, user);
                            user._chat_dialog.setModal(false);
                        }
                        if(user._chat_dialog.isVisible() == false) {
                            user._chat_dialog.setVisible(true);
                        }
                    }
                }
            }
        });
        _l_users.setCellRenderer(new LCR_Panel());

        this.add(new JScrollPane(_l_users));
        this.pack();
    }
    public void _Recv_Packet(int[] head, DatagramPacket packet) {
        Logger._udp_client._Debug(null);
        if(head[1] == UDP_Protocol._topic_logout) {
            /*
            recv: #brilliant#timestamp
            */
            String   recv_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
            String[] items     = Bytes._Split(recv_body, UDP_Protocol._sign_logout,2);
            User user = _Get_User(items[0]);
            if(user != null) {
                user._online    = -UDP_Protocol._echo_countdown;
                user._timestamp = items[1];
                if(user._chat_dialog != null) {
                    user._chat_dialog.setTitle(user._identity + "下线");
                }
                this.repaint();
            }
        } else if(head[1] == UDP_Protocol._topic_user) {
            User fresh = new User(packet.getData(), new int[] { UDP_Protocol._udp_head_size });
//            _dlm_users.addElement(fresh);
            boolean hitted = false;
            for(int i = 0; i < _dlm_users.size(); i += 1) {
                User user = _dlm_users.get(i);
                if(fresh._identity.equals(user._identity) == true) {
                    hitted = true;
                    break;
                }
            }
            if(hitted == false) {
                _dlm_users.addElement(fresh);
            }
        } else if(head[1] == UDP_Protocol._topic_users) {
            ArrayList<User> users = User._Users_From_Byte(head, packet.getData());
            _dlm_users.clear();
            _dlm_users.addElement(_group);
            _dlm_users.addAll(users);
        } else if(head[1] == UDP_Protocol._topic_peer) {
            /*
            recv: @user_send@user_recv@message
            */
            String   recv_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
            String[] items     = Bytes._Split(recv_body, UDP_Protocol._sign_peer, 3);
            User user = _Get_User(items[0]);
            if(user != null) {
                if(user._chat_dialog == null) {
                    user._chat_dialog = new ChatDialog(_handler, user);
                    user._chat_dialog.setModal(false);
                }
                user._chat_dialog._Recv_Packet(recv_body);
            }
        } else if(head[1] == UDP_Protocol._topic_echo) {
            /*
            recv: #user#online#timestamp
            */
            String   recv_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
            String[] items     = Bytes._Split(recv_body, UDP_Protocol._sign_echo, 3);
            User user = _Get_User(items[0]);
            if(user != null) {
                user._online    = Integer.parseInt(items[1]);
                user._timestamp = items[2];
                this.repaint();
            }
        } else if(head[1] == UDP_Protocol._topic_group) {
            /*
            recv: &user_send&group_recv&message
            */
            String   recv_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
            String[] items     = Bytes._Split(recv_body, UDP_Protocol._sign_group, 3);
            if(items[1].equals(_group._identity)) {
                if(_group._chat_dialog == null) {
                    _group._chat_dialog = new ChatDialog(_handler, _group);
                    _group._chat_dialog.setModal(false);
                }
                _group._chat_dialog._Recv_Packet(recv_body);
            }
        }
    }
    public User _Get_User(String identity) {
        Logger._udp_client._Note(null);
        for(int i = 0; i < _dlm_users.size(); i += 1) {
            User user = _dlm_users.get(i);
            if(user != null && identity.equals(user._identity) == true) {
                return user;
            }
        }
        return null;
    }
}

public class UDP_Protocol_Client {
    static class Thread_Recv extends Thread {
        public UDP_Protocol_Client _handler = null;
        public Thread_Recv(UDP_Protocol_Client handler) {
            Logger._udp_client._Debug(null);
            _handler = handler;
            this.start();
        }
        @Override
        public void run() {
            Logger._udp_client._Debug(null);
            try {
                DatagramSocket client = _handler._client;
                while(true) {
                    int[]          recv_head   = new int[UDP_Protocol._udp_head_size / 4];
                    DatagramPacket recv_packet = new DatagramPacket(new byte[UDP_Protocol._udp_buffer_init], UDP_Protocol._udp_buffer_init);
                    client.receive(recv_packet);
                    if(recv_packet.getLength() < UDP_Protocol._udp_head_size) {
                        continue;
                    }
                    Bytes._Ints_From_Bytes(recv_head, recv_packet.getData(), 0);
                    if(recv_packet.getLength() != UDP_Protocol._udp_head_size + recv_head[0]) {
                        Logger._udp_client._Warn("recv_packet.getLength() != UDP_Protocol._udp_head_size + recv_head[0]");
                        continue;
                    }
                    Logger._udp_client._Warn("[%s:%s] %s", recv_head[0], UDP_Protocol._topics[recv_head[1]], new String(recv_packet.getData(), UDP_Protocol._udp_head_size, recv_head[0], UDP_Protocol._charset_sink));
                    if(recv_head[1] == UDP_Protocol._topic_login) {
                        _handler._login_dialog._Recv_Packet(recv_head, recv_packet);
                    } else if(recv_head[1] == UDP_Protocol._topic_logout) {
                        _handler._main_dialog._Recv_Packet(recv_head, recv_packet);
                    }
                    else if(recv_head[1] == UDP_Protocol._topic_user) {
                        _handler._main_dialog._Recv_Packet(recv_head, recv_packet);
                    }
                    else if(recv_head[1] == UDP_Protocol._topic_users) {
                        _handler._main_dialog._Recv_Packet(recv_head, recv_packet);
                    } else if(recv_head[1] == UDP_Protocol._topic_peer) {
                        _handler._main_dialog._Recv_Packet(recv_head, recv_packet);
                    } else if(recv_head[1] == UDP_Protocol._topic_group) {
                        /*
                        recv: &user_send&group_recv&message
                        */
                        _handler._main_dialog._Recv_Packet(recv_head, recv_packet);
                    } else if(recv_head[1] == UDP_Protocol._topic_echo) {
                        /*
                        recv:
                        send: #user
                        recv: #user#online#timestamp
                        */
                        Bytes send_buffer = new Bytes(UDP_Protocol._udp_buffer_init, UDP_Protocol._udp_head_size);
                        if(recv_head[0] == 0) {
                            String send_body = UDP_Protocol._sign_echo + _handler._main_dialog._self._identity;
                            send_buffer._Append(send_body, UDP_Protocol._charset_sink);
                            int[] send_head = new int[] { send_buffer._length - UDP_Protocol._udp_head_size, UDP_Protocol._topic_echo };
                            send_buffer._Cover(0, send_head);
                            _handler._Send_Packet(send_head, new DatagramPacket(send_buffer._data, 0, send_buffer._length, recv_packet.getSocketAddress()));
                        } else {
                            _handler._main_dialog._Recv_Packet(recv_head, recv_packet);
                        }
                    }
                }
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    }

    public DatagramSocket    _client         = null;
    public InetSocketAddress _server_address = null;
    public Thread_Recv       _thread_recv    = null;
    public MainDialog        _main_dialog    = null;
    public LoginDialog       _login_dialog   = null;
    public UDP_Protocol_Client() {
        Logger._udp_client._Debug(null);
        try {
            _client         = new DatagramSocket();
            Logger._udp_client._Warn("_client.getLocalSocketAddress()=%s", _client.getLocalSocketAddress());
            _server_address = new InetSocketAddress(UDP_Protocol._server_ipv4, UDP_Protocol._server_port);
            _thread_recv    = new Thread_Recv(this);
            _main_dialog    = new MainDialog(this);
            _login_dialog   = new LoginDialog(this);
            _login_dialog.setModal(true);
            _login_dialog.setVisible(true);
            _main_dialog.setModal(false);
            _main_dialog.setVisible(true);
            while(true);
        } catch (Exception exception) {
            exception.printStackTrace();
        } finally {
            _client.close();
        }
    }
    public void _Send_Packet(int[] head, DatagramPacket packet) {
        Logger._udp_client._Debug(null);
        try {
            String send_body = new String(packet.getData(), UDP_Protocol._udp_head_size, head[0], UDP_Protocol._charset_sink);
            Logger._udp_client._Warn("%s [%s: %s] %s", packet.getSocketAddress(), head[0], UDP_Protocol._topics[head[1]], send_body);
            _client.send(packet);
        } catch(Exception exception) {
            exception.printStackTrace();
        }
    }

    static public void main(String[] args) {
        Logger._udp_server._level = Logger._debug;
        Logger._udp_client._level = Logger._debug;
        Logger._udp_client._Note(null);
        new UDP_Protocol_Client();
    }
}
