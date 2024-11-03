const express = require('express');
const app = express();
const http = require('http');
const server = http.createServer(app);

const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');
const { Server } = require('socket.io');

const port = new SerialPort({
 path: 'enter-path-here', //enter path
 baudRate: 9600,
 dataBits: 8,
 parity: 'none',
 stopBits: 1,
 flowControl: false
});

const parser = port.pipe(new ReadlineParser({ delimiter: '\r\n' }));
const io = new Server(server, { cors: { origin: "*" } });

const mainNamespace = io.of('/');

mainNamespace.on('connection', socket => {
  socket.on('message', function(data) {
      port.write(data);
  });
});

app.use('/', express.static('public'));

server.listen(3500, () => {
  console.log('Server is running on port 3500');
 });
