<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Update</title>
</head>
<body>

<div>name: <c:out value="${requestScope.flower.name}"/> </div>
<div>balance: <c:out value="${requestScope.flower.balance}"/> </div>

<br />

<form method="post" action="<c:url value='/update'/>">

    <label>new name: <input type="text" name="name" /></label><br>

    <input type="number" hidden name="id" value="${requestScope.flower.id}"/>

    <input type="submit" value="Ok" name="Ok"><br>
</form>
</body>
</html>