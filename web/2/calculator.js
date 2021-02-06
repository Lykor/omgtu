$(document).ready(function () {

    let firstNumber = "";
    let secondNumber = "";
    let operator = "";
    let result = 0;

    $('.number').on("click", function () {

      if (operator === "") {
        firstNumber += $(this).attr("value");
        firstNumber = parseInt(firstNumber);
        $('#first-number').text(firstNumber);

      }
      else {
        secondNumber += $(this).attr("value");
        secondNumber = parseInt(secondNumber);
        $('#second-number').text(secondNumber);
      }
    })

    $('.operator').on("click", function () {
      if (operator !== "") {
        firstNumber = result;
        secondNumber = 0;
        operator = $(this).attr("value")
        result = 0;
        $('#first-number').text(firstNumber);
        $('#second-number').text('');
        $('#operator').text(operator);
        $('#result').text('');
      } else {
        operator = $(this).attr("value")
        $('#operator').text(operator);
        console.log(operator)
      }
    })

    $('.equal').on("click", function () {
      calculate(firstNumber, secondNumber, operator)
      $('#result').text(result);
      console.log(result)
    })

    $('.clear').on("click", function () {
      firstNumber = 0;
      secondNumber = 0;
      operator = "";
      result = 0;
      $('#first-number').text('');
      $('#second-number').text('');
      $('#operator').text('');
      $('#result').text('');
    })

    $('.tip').on("click", function () {
      result += result * .10;
      $('#result').text(result);
    })

    function calculate(firstNumber, secondNumber, operator) {

      if (operator === "+") {
        result = firstNumber + secondNumber;
      } else if (operator === "-") {
        result = firstNumber - secondNumber;
      }
      else if (operator === "X") {
        result = firstNumber * secondNumber;
      }
      else if (operator === "/") {
        result = firstNumber / secondNumber;
      }
      else if (operator === "^") {
        result = Math.pow(firstNumber, secondNumber);
      }
    }
  });