<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>Title</title>

</head>
<body>

<div align="center">

<h2>Все пользователи</h2><br/>

<c:forEach var="flower" items="${requestScope.flowers}">
  <ul>

    <li>Имя:<br> <c:out value="${flower.name}"/></li>
    <li>Наличие:<c:out value="${flower.balance}"/></li>
    <li>Цена:<c:out value="${flower.price}"/></li>
    <li>Оценка:<c:out value="${flower.rating}"/></li>

    <form method="post" action="<c:url value='/delete'/>">
      <input type="number" hidden name="id" value="${flower.id}" />
      <input type="submit" name="delete" value="Удалить"/>
    </form>

    <form method="get" action="<c:url value='/update'/>">
      <input type="number" hidden name="id" value="${flower.id}" />
      <input type="submit" value="Редактированть"/>
    </form>

  </ul>
  <hr />

</c:forEach>

<h2>Создание нового пользователя</h2><br />

<form method="post" action="<c:url value='/addFlower'/>">

  <label><input type="text" name="name"></label>Имя<br>
  <label><input type="number" name="balance"></label>Наличии<br>
  <label><input type="number" name="price"></label>Цена<br>
  <label><input type="number" name="rating"></label>Оценка<br>

  <input type="submit" value="Ok" name="Ok"><br>
</form>
<br>

<form method="post" action="<c:url value='/search'/>">

  <label><input type="text" name="name"></label>Имя<br>

  <input type="submit" value="Ok" name="Ok"><br>
</form>


<c:forEach var="flowerS" items="${requestScope.flowersSearch}">
  <ul>

    <li>Имя: <c:out value="${flowerS.name}"/></li>
    <li>Наличие:<c:out value="${flowerS.balance}"/></li>
    <li>Цена:<c:out value="${flowerS.price}"/></li>
    <li>Оценка:<c:out value="${flowerS.rating}"/></li>


  </ul>
  <hr />

</c:forEach>

</div>

</body>
</html>
