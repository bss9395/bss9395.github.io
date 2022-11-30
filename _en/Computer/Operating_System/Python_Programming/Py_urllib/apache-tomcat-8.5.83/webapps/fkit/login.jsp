<%@ page contentType="text/html; charset=utf-8" language="java" errorPage="" %>
<%
String username = request.getParameter("username");  // may raise error.
String password = request.getParameter("password");  // may raise error.
if (username.equals("bss9395") && password.equals("Pass")) {
	session.setAttribute("username" , username);
	out.println("Login Successfully!");
}
else {
	out.println("Login Failed!");
}
%>

