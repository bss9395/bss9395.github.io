<%@ page contentType="text/html; charset=utf-8" language="java" errorPage="" import="java.io.*" %>
<%
BufferedReader reader = new BufferedReader(new InputStreamReader(request.getInputStream()));
String line = null;
//while ((line = reader.readLine()) != null) {
//	out.println(line);
//}
String name = request.getParameter("name");
String pass = request.getParameter("pass");
if (name != null && pass != null && name.equals("bss9395") && pass.equals("password")) {
	session.setAttribute("user" , name);
	out.println("恭喜您，登录成功！");
} else if((line = reader.readLine()) != null) {
	out.println(line);
	String[] params = line.split("&");
	if(params[0] != null && params[1] != null && params[0].equals("name=bss9395") && params[1].equals("pass=password")) {
		session.setAttribute("user" , "bss9395");
		out.println("恭喜您，登录成功！");
	} else {
		out.println("对不起，用户名、密码不符合！");
	}
}
%>
