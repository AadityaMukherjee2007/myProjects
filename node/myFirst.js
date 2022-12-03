var http = require('http');
var dt = require('./timeModule')

http.createServer(function (req, res)
{
	res.writeHead(200, {'Content-Type': 'text/html'});
	res.write("DateTime: " + dt.dateTime());
	res.end();
}).listen(8080);