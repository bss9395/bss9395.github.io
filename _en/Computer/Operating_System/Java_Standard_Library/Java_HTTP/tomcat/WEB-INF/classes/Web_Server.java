/* Web_Server.java
Author: BSS9395
Update: 2023-03-23T21:37:00+08@China-Shanghai+08
Design: Web Server
*/

import javax.websocket.*;
import java.util.*;
import javax.websocket.server.*;

@ServerEndpoint(value="/WebServer")
public class Web_Server {
	static List<Session> clients = Collections.synchronizedList(new ArrayList<Session>());
	@OnOpen
	public void start(Session session) {
		clients.add(session);
	}
	@OnMessage
	public void message(String message, Session session)
	    throws Exception {
		for (var client : clients) {
			RemoteEndpoint.Basic remote = client.getBasicRemote();
			remote.sendText(message);
		}
	}
	@OnClose
	public void end(Session session, CloseReason closeReason) {
		clients.remove(session);
	}
	@OnError
	public void error(Session session, Throwable throwable)	{
		clients.remove(session);
	}
}
