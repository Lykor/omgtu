<!DOCTYPE html>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>

<head>
    <title>
        GameStore
    </title>
    <link rel="stylesheet" href="styles.css">
</head>

<body>
    <table>
        <tr>
            <td>
                <form onsubmit="event.preventDefault();Form();" autocomplete="off">
                    <div>
                        <label>Игра</label>
                        <input type="text" name="name" id="name">
                    </div>
                    <div>
                        <label>Жанр</label>
                        <input type="text" name="zhanr" id="zhanr">
                    </div>
                    <div>
                        <label>Год Выпуска</label>
                        <input type="text" name="year" id="year">
                    </div>
                    <div>
                        <label>Отзывы</label>
                        <input type="text" name="review" id="review">
                    </div>
                    <div>
                    	<label>Оценка</label>
                    	<input type="text" name="rating" id="rating">	
                    </div>
                    <div  class="form-action-buttons">
                        <input type="submit" value="Submit">
                    </div>
                </form>
            </td>
            <td>
                <table class="list" id="games">
                    <thead>
                        <tr>
                            <th>Игра</th>
                            <th>Жанр</th>
                            <th>Год Выпуска</th>
                            <th>Отзывы</th>
                            <th>Оценка</th>
                        </tr>
                    </thead>
                    <tbody>

                    </tbody>
                </table>
            </td>
        </tr>
    </table>
    <script>
	
function Form() {    
        var person; // переменная в которой будет объект для отправки в таблицу
        read(); // чтение с формы и передача json в сервлет        
        	var xhr = new XMLHttpRequest(); // создаем экземпляр объекта XMLHttpRequest
            xhr.open('GET','http://localhost:8080/gameShop/gameAdd',false); //задается открытие (open) синхронного соединение с адресом localhost..
			xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded'); // Устанавливает заголовок 'Content-Type' запроса со значением 'application/x-www-form-urlencoded'. Если заголовок с таким name уже есть - он заменяется
			// application/x-www-form-urlencoded - вид кодировки
			// Это указание для сервера – как обрабатывать (раскодировать) пришедший запрос
		   xhr.send(null); // запрос без данных
            var msg = xhr.responseText; // текст ответа сервера
            person = JSON.parse(msg); // Возвращает объект Object, соответствующий переданной строке JSON
            insert(person); // передаем объект в таблицу         
        reset();    
}

function read() { // чтение из формы и отправка в сервлет
    var person = {}; // пустой объект
    person["name"] = document.getElementById("name").value; // добавляем значения в объект из формы 
    person["zhanr"] = document.getElementById("zhanr").value;
    person["year"] = document.getElementById("year").value;
    person["review"] = document.getElementById("review").value;
    person["rating"] = document.getElementById("rating").value;
    var xhr = new XMLHttpRequest(); // создаем экземпляр объекта XMLHttpRequest
    xhr.open('POST','http://localhost:8080/gameShop/gameAdd',false); //задается открытие (open) синхронного соединение с адресом localhost..
	var jsonData = JSON.stringify(person);  // преобразуем в json строку  
	xhr.send(jsonData);    // отправляем запрос с json строкой
}

function insert(data) {
    var table = document.getElementById("games").getElementsByTagName('tbody')[0]; // получаем тэг
    var newRow = table.insertRow(table.length); // создаем новую строку
    cell1 = newRow.insertCell(0); // создаем новую ячейку
    cell1.innerHTML = data.name; // записываем данные в ячейку
    cell2 = newRow.insertCell(1);
    cell2.innerHTML = data.zhanr;
    cell3 = newRow.insertCell(2);
    cell3.innerHTML = data.year;
    cell4 = newRow.insertCell(3);
    cell4.innerHTML = data.review;
    cell5 = newRow.insertCell(4);
    cell5.innerHTML = data.rating;
    
}

function reset() { // очистка формы добавления в таблицу
    document.getElementById("name").value = ""; // по айдишнику очищаем значения
    document.getElementById("zhanr").value = "";
    document.getElementById("year").value = "";
    document.getElementById("review").value = "";
    document.getElementById("rating").value = "";   
}
</script>
</body>

</html>