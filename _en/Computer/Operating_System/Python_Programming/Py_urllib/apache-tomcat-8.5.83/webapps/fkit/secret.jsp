<%@ page contentType="text/html; charset=utf-8" language="java" errorPage="" %>
<%
Object username = session.getAttribute("username");  // may raise error
if(username != null && username.toString().trim().equals("bss9395")) {
%>
<!DOCTYPE html>
<html>
<head>
	<meta name="author" content="bss9395" />
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<title>安全资源</title>
</head>
<body>
	bss9395登录成功。
</body>
</html>
<%
} else {
	out.println("您没有被授权访问该页面");	
}
%>

