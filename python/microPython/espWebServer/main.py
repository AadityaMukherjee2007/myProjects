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
	<link rel="icon" type="image/x-icon" href="https://image.shutterstock.com/image-vector/cloud-iot-icon-wifi-sign-260nw-1822313777.ico">
	
	<style>
        h2
        {
            text-align: center;
        }
		body
		{
			align-content: center;
			align-self: center;
		}

		.b
		{
			text-decoration: none;
			border: none;
			border-radius: 5px;
			background-color: grey;
			color: white;
			padding: 15px 30px;
		}

		.device
		{
			float: left;
			border-radius: 5px;
			background-color: lightgrey;
			width: 300px;
			align-content: center;
			text-align: center;
			box-shadow: 0 4px 8px 0 darkgrey;
			transition:  0.3s;
			padding: 10px;
			margin: 20px;
		}

		.device:hover 
		{
			box-shadow: 0 8px 16px 0 darkgrey;
		}

		.d_1_2
		{
			float:  left;
			margin-left: 20%;
			margin-top: 5%;
			margin-bottom: auto;
		}

		.d_3_4
		{
			float: left;
			margin-left: 20%;
			margin-top: 5%;
			margin-bottom: auto;
		}

		.dateTime
		{
			margin-top: auto;
			margin-bottom: auto;
		}
	</style>

</head>

<body>
	<script type="text/javascript">
        const Http = new XMLHttpRequest();
        const url='http://192.168.0.182/?d1=on';
		function refresh()
		{
			function update()
			{
				var today = new Date();
				var date = today.getDate() + "-" + (today.getMonth() + 1) + "-" + today.getFullYear();
				var time = today.getHours() + ":" + today.getMinutes() + ":" + today.getSeconds();
                console.log(time);
                if (time == "3:40:0")
                {
                    Http.open("GET", url);
                    Http.send();
                }
			}
			setInterval(update, 1000);
		}
		refresh();
	</script>

	<h2>IOT Panel</h2>

	<div class="d_1_2">
		<div class="device" style="margin-right: 100px;">
			<h1>Device 1</h1>
			<p>GPIO state: """ + d1_state + """</p>
			<div class="container">
				<a href="/?d1=on"><button class="b" id="rm" style="margin-right: 10px;">ON</button></a>
				<a href="/?d1=off"><button class="b">OFF</button></a>
			</div>
		</div>

		<div class="device">
			<h1>Device 2</h1>
			<p>GPIO state: """ + d2_state + """</p>
			<div class="container">
				<a href="/?d2=on"><button class="b" id="rm" style="margin-right: 10px;">ON</button></a>
				<a href="/?d2=off"><button class="b">OFF</button></a>
			</div>
		</div>
	</div>

	<div class="d_3_4">
		<div class="device" style="margin-right: 100px;">
			<h1>Device 3</h1>
			<p>GPIO state: """ + d3_state + """</p>
			<div class="container">
				<a href="/?d3=on"><button class="b" id="rm" style="margin-right: 10px;">ON</button></a>
				<a href="/?d3=off"><button class="b">OFF</button></a>
			</div>
		</div>

		<div class="device">
			<h1>Device 4</h1>
			<p>GPIO state: """ + d4_state + """</p>
			<div class="container">
				<a href="/?d4=on"><button class="b" style="margin-right: 10px;">ON</button></a>
				<a href="/?d4=off"><button class="b">OFF</button></a>
			</div>
		</div>
	</div>
</body>	
</html>"""
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
