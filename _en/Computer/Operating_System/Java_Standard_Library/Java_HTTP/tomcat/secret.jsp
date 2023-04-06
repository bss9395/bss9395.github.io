<%@ page contentType="text/html; charset=utf-8" language="java" errorPage="" %>
<%
Object user = session.getAttribute("user");
if(user != null && user.toString().trim().equals("bss9395")) {
%>
<!DOCTYPE html>
<html>
<head>
	<meta name="author" content="Yeeku.H.Lee(CrazyIt.org)" />
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<title> 安全资源 </title>
</head>
<body>
	安全资源，只有登录用户<br/>
	且用户名是crazyit.org才可访问该资源
</body>
</html>
<%
} else {
	out.println("您没有被授权访问该页面");	
}
%>

