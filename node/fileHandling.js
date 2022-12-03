var fs = require('fs');

fs.open('demoFile.txt', 'w', function(err){
	if (err) throw err;
	console.log('File Opened!');
});

fs.writeFile('demoFile.txt', 'Hello, World!', function(err){
	if (err) throw err;
	console.log('Replaced!')
});

fs.appendFile('demoFile.txt', '\nNode is Awesome...', function(err){
	if (err) throw err;
	console.log("Updated!");
});

fs.rename('demoFile.txt', 'NewFile.txt', function(err){
	if (err) throw err;
	console.log('Renamed!');
});

/*fs.unlink('NewFile.txt', function (err) {
	if (err) throw err;
	console.log('File Deleted')
});*/
