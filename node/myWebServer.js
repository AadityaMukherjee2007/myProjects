var http = require('http');
var fs = require('fs');

var port = 8000;

var server = http.createServer(function (req, res){
	if (req.url == "/")
	{
		fs.readFile('myWebServer.html', function(err, read){
			if (err)
			{
				res.writeHead(404, {'Content-Type': 'text/html'});
				res.write("File not found!");
			}
			else
			{
				res.write(read);
			}

			res.end();
		});
	}
	else
	{
		res.writeHead(404, {'Content-Type': 'text/html'});
		res.write("File not found!");
		res.end();
	}
});

server.listen(port, function(err){
	if (err) 
	{
		console.log("Something went wrong!", err);
	}
	else
	{
		console.log("Server is listening on port " + port + "...");
	}
});

