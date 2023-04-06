/* Java_ServerEndpoint.java
Author: BSS9395
Update: 2023-03-23T19:56:00+08@China-Shanghai+08
Design: Java Standard Library: ServerEndpoint
*/

import javax.websocket.*;
import javax.websocket.server.*;

@ServerEndpoint(value="/WebSocket")
public class Java_ServerEndpoint {
	@OnOpen
	public void start(Session session) {
		System.err.printf("[start] session.getId() = %s%n", session.getId());
	}
	@OnMessage
	public void message(String message, Session session)
	    throws Exception {
		System.err.printf("[message] message = %s%n", message);
		RemoteEndpoint.Basic remote = session.getBasicRemote();
		remote.sendText("Hello, Client!");
	}
	@OnClose
	public void end(Session session, CloseReason closeReason) {
		System.err.printf("[end] session.getId() = %s%n", session.getId());
	}
	@OnError
	public void error(Session session, Throwable throwable) {
		System.err.printf("[error] session.getId() = %s%n", session.getId());
	}
}
