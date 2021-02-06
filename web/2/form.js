$(
    function () {
      $("#test-table").FullTable({
        "alwaysCreating": true,
        "selectable": true,
        "fields": {
          "lastname": {
            "mandatory": true,
            "errors": {
              "mandatory": "Last name is mandatory"
            }
          },
          "age": {
            "type": "integer",
            "mandatory": false,
            "validator": function (age) {
              if (age >= 0) {
                return true;
              } else {
                return false;
              }
            },
            "errors": {
              "type": "Age must be an integer number",
              "mandatory": "Age is mandatory",
              "validator": "Age cannot be negative"
            }
          },
          "gender": {
            "options": [
              {
                "title": "Male",
                "value": "xy"
              },
              {
                "title": "Female",
                "value": "xx"
              }
            ],
            "mandatory": true,
            "placeholder": "Select one",
            "errors": {
              "mandatory": ""
            }
          },
          "height": {
            "type": "integer",
            "mandatory": false,
            "validator": function (age) {
              if (age >= 0) {
                return true;
              } else {
                return false;
              }
            },
            "errors": {
              "type": "Height must be a number",
              "mandatory": "",
              "validator": ""
            }
          },
          "telephone": {
            "type": "integer",
            "mandatory": false,
            "validator": function (age) {
              if (age >= 0) {
                return true;
              } else {
                return false;
              }
            }
          },
          "mail": {
            "mandatory": true,
            "errors": {
              "mandatory": ""
            }
          }
        }});
      $("#test-table-add-row").click(function () {
        $("#test-table").FullTable("addRow");
      });
      $("#test-table-get-value").click(function () {
        console.log($("#test-table").FullTable("getData"));
      });
      $("#test-table").FullTable("on", "error", function (errors) {
        for (var error in errors) {
          error = errors[error];
          console.log(error);
        }
      });
      $("#test-table").FullTable("draw");
    }
  );