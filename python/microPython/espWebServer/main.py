def server():
    if led.value() == 1:
        gpio_state = "ON"
    else:
        gio_state = "OFF"
        
    html = """
<!DOCTYPE html>
<html>
<head>
<title>ESP Web Server</title>
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<style>
.b
{
text-decoration: none;
border: none;
background-color: grey;
color: white;
padding: 15px 30px;
}
</style>

</head>

<body>
<h1>Inbuilt LED</h1>
<p>GPIO state: """ + gpio_state + """
<p>
<a href="/?led=on"><button class="b" style="margin-right: 10px;">ON</button></a>
<a href="/?led=off"><button class="b">OFF</button></a>
</p>
</body>	
</html>
"""
    return html

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 80))
s.listen(5)

while True:
    conn, addr = s.accept()
    print('Got a connection from', addr)
    
    request = conn.recv(1024)
    request = str(request)
    print('Content =', request)
    
    led_on = request.find('/?led=on')
    led_off = request.find('/?led=off')
    
    if led_on == 6:
        led.value(1)
        print('LED On')
    elif led_off == 6:
        led.value(0)
        print('LED Off')
    
    response = server()
    conn.send('HTTP/1.1 2000 OK\n')
    conn.send('Content-Type: text/html\n')
    conn.send('Connection: close\n\n')
    conn.sendall(response)
    con.close()
    