
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <style type="text/css" media="all">
           form {
           text-align: center;
           }
    </style>
    <title>Математика по политеховски</title>
  </head>
  <body><form action="servlet" method="post">
    <div align="center"><font size="+7"> Тест "Математика"</font> </div>

    ${question}<br>
    <input type = "radio" name="id" value=${answer1}>${answer1}<br>
    <input type = "radio" name="id" value=${answer2}>${answer2}<br>
    <input type = "radio" name="id" value=${answer3}>${answer3}<br>
    <input type = "radio" name="id" value=${answer4}>${answer4}<br>
    <input type="submit" value="продолжить">

  </form>

  <form action="servlet" method="get">
    <input type = "submit" value="заново">
  </form>



  </body>
</html>
