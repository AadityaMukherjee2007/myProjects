def server():
    if d1.value() == 0:
        d1_state = "ON"
    elif d1.value() == 1:
        d1_state = "OFF"
    if d2.value() == 0:
        d2_state = "ON"
    elif d2.value() == 1:
        d2_state = "OFF"
    if d3.value() == 0:
        d3_state = "ON"
    elif d3.value() == 1:
        d3_state = "OFF"
    if d4.value() == 0:
        d4_state = "ON"
    elif d4.value() == 1:
        d4_state = "OFF"
        
    html = """<!DOCTYPE html>
<html>
<head>
<title>ESP Web Server</title>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<link rel="icon" href="data:,">
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

<div style="margin-botton: 10px;">
<h1>Device 1</h1>
<p>GPIO state: """ + d1_state + """
<p>
<a href="/?d1=on"><button class="b" id="rm" style="margin-right: 10px;">ON</button></a>
<a href="/?d1=off"><button class="b">OFF</button></a>
</p>
</div>

<div style="margin-botton: 10px;">
<h1>Device 2</h1>
<p>GPIO state: """ + d2_state + """
<p>
<a href="/?d2=on"><button class="b" id="rm" style="margin-right: 10px;">ON</button></a>
<a href="/?d2=off"><button class="b">OFF</button></a>
</p>
</div>

<div style="margin-botton: 10px;">
<h1>Device 3</h1>
<p>GPIO state: """ + d3_state + """
<p>
<a href="/?d3=on"><button class="b" id="rm" style="margin-right: 10px;">ON</button></a>
<a href="/?d3=off"><button class="b">OFF</button></a>
</p>
</div>

<div>
<h1>Device 4</h1>
<p>GPIO state: """ + d4_state + """
<p>
<a href="/?d4=on"><button class="b" id="rm" style="margin-right: 10px;">ON</button></a>
<a href="/?d4=off"><button class="b">OFF</button></a>
</p>
</div>

</body>	
</html>"""
    return html

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 80))
s.listen(3)

while True:
    conn, addr = s.accept()
    print('Got a connection from', addr)
    
    request = conn.recv(1024)
    request = str(request)
    print('Content =', request)
    
    d1_on = request.find('/?d1=on')
    d1_off = request.find('/?d1=off')
    d2_on = request.find('/?d2=on')
    d2_off = request.find('/?d2=off')
    d3_on = request.find('/?d3=on')
    d3_off = request.find('/?d3=off')
    d4_on = request.find('/?d4=on')
    d4_off = request.find('/?d4=off')
    
    if d1_on == 6:
        d1.value(0)
        print('d1 On')
    elif d1_off == 6:
        d1.value(1)
        print('d1 Off')
    elif d2_on == 6:
        d2.value(0)
        print('d2 On')
    elif d2_off == 6:
        d2.value(1)
        print('d2 Off')
    elif d3_on == 6:
        d3.value(0)
        print('d3 On')
    elif d3_off == 6:
        d3.value(1)
        print('d3 Off')    
    elif d4_on == 6:
        d4.value(0)
        print('d4 On')
    elif d4_off == 6:
        d4.value(1)
        print('d4 Off')
    
    response = server()
    conn.send('HTTP/1.1 200 OK\n')
    conn.send('Content-Type: text/html\n')
    conn.send('Connection: close\n\n')
    try:
        conn.sendall(response)
    except SocketError as e:
        if e.errno != err.ECONNRESET:
            raise
        pass
    conn.close()
