<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>Цветочник</title>

</head>
<body>
<div align="center">

<c:forEach var="flower" items="${requestScope.flowers}">
  <ul>

    <li>Имя: <c:out value="${flower.name}"/></li>
    <li>Остаток:<c:out value="${flower.balance}"/></li>
    <li>Цена:<c:out value="${flower.price}"/></li>
    <li>Оценка:<c:out value="${flower.rating}"/></li>


  </ul>
  <hr />

</c:forEach>

<form method="post" action="<c:url value='/addFlower'/>">

  <label><input type="text" name="name"></label>Имя<br>

  <label><input type="number" name="balance"></label>Остаток<br>
  <label><input type="number" name="price"></label>Цена<br>
  <label><input type="number" name="rating"></label>Оценка<br>

  <input type="submit" value="Ok" name="Ok"><br>
</form>

</div>
</body>
</html>
