$(document).ready(function () {
    $("#phone").mask("+7 (999) 99 99 999");
    $(".button").magnificPopup();

    $("#form").submit(function (){
        $('.loader').show();
        $ajax({
            type: "POST",
            url: "/mail.php",
            data: $(this).serialize(),
            beforeSend:function(){
                $('.loader').show();
                setTimeout(function() {
                }, 6000);
            },
            success:function(data){
                $('.loader').hide();
                if(data=='success') alert("Сообщение отправлено");
                setTimeout(function() {
                }, 10000);
            },
            error: function(XMLHttpRequest, textStatus, errorThrown) { 
                alert("Status: " + textStatus); alert("Error: " + errorThrown); 
            } 
        });
            
        });
});