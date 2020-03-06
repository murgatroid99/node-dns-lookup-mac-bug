const dns = require('dns');

const aaaaRecordName = 'loopback6.unittest.grpc.io';
const bothRecordName = 'loopback46.unittest.grpc.io';
const localhost = 'localhost';

const dnsNames = [
  'loopback6.unittest.grpc.io',
  'loopback46.unittest.grpc.io',
  'localhost'
];

for (const name of dnsNames) {
  dns.lookup(name, {all: true}, (error, result) => {
    console.log('Result of dns.lookup for name', name);
    console.log(error, result);
  });
  dns.resolve4(name, (error, result) => {
    console.log('Result of dns.resolve4 for name', name);
    console.log(error, result);
  });
  dns.resolve6(name, (error, result) => {
    console.log('Result of dns.resolve6 for name', name);
    console.log(error, result);
  });
}
