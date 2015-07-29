var net = require('net');

var client = net.connect({port: 1138, host: 'localhost'}, function() {
	console.log('connecte');
});

client.setEncoding('utf8');

client.on('data', function (data) {
	console.log(data);
	if (data === 'BIENVENUE\n') {
		client.write('ALPHA\n');
	}
});

process.stdin.setEncoding('utf8');
process.stdin.on('readable', function() {
	var chunk = process.stdin.read();
	if (chunk !== null)
	{
		client.write(chunk);
		chunk = null;
	}
});
