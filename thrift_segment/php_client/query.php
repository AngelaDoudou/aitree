<?php

define('THRIFT_PHP_LIB', __DIR__.'/lib/php/lib');
define('GEN_PHP_DIR', __DIR__.'/gen-php');

require_once THRIFT_PHP_LIB.'/Thrift/ClassLoader/ThriftClassLoader.php';
require_once __DIR__ . '/gen-php/Article/ArticleService.php';
require_once __DIR__ . '/gen-php/Article/Types.php';

use Thrift\ClassLoader\ThriftClassLoader;

$loader = new ThriftClassLoader();
$loader->registerNamespace('Thrift', THRIFT_PHP_LIB);
// register your namespace
$loader->registerDefinition('Article', GEN_PHP_DIR);
$loader->register();

// include here the protocols and transports that you need
use Thrift\Protocol\TBinaryProtocol;
use Thrift\Transport\TSocket;
use Thrift\Transport\THttpClient;
use Thrift\Transport\TBufferedTransport;
use Thrift\Exception\TException;

// Init
$socket = new TSocket('127.0.0.1', 9090);
$transport = new TBufferedTransport($socket, 1024, 1024);
$protocol = new TBinaryProtocol($transport);
$client = new \Article\ArticleServiceClient($protocol);
// Config
$socket->setSendTimeout(30 * 1000);
$socket->setRecvTimeout(30 * 1000);
// Connect
$transport->open();

#print_r($client->Segment($_REQUEST['q'],20));
#print_r($client->Segment("一个走向辉煌的网站,小米是雷军的，雷军是谁的？",13));

$result = [];
if (!isset($_POST['q']) || empty($_POST['q'])) {
    //$query = "请输入查询词";
    //$queryArray[] = $query;
    $result[] = array(
        "tag" => "请输入查询词",
        "score" => 55,
    ); 
} else {
    $query = $_POST['q'];
    //$queryArray = ch2arr($query);
    $queryArray = $client->Segment($query,20);
    foreach ($queryArray as $key => $value) {
        $result[] = array(
            "tag" => $value->word,
            "score" => $value->weight*3,
        ); 
    }
}

// Close
$transport->close();

function mlog($data) {
    file_put_contents("log.txt", json_encode($data, JSON_UNESCAPED_UNICODE)."\n", FILE_APPEND);
}



/**
 * 中文字符串转换为单个字的数组
 * @param mixed $str 
 * @return void
 */
function ch2arr($str)
{
    $length = mb_strlen($str, 'utf-8');
    $array = [];
    for ($i=0; $i<$length; $i++)  
        $array[] = mb_substr($str, $i, 1, 'utf-8');    
    return $array;
}  



mlog($result);
echo json_encode($result);

