<?php

function mlog($data) {
    file_put_contents("log.txt", json_encode($data, JSON_UNESCAPED_UNICODE)."\n", FILE_APPEND);
}

/*
$result = array(
    0 => array("tag" => "科技", "score" => 91.7),
    1 => array("tag" => "名人", "score" => 80.1),
    2 => array("tag" => "手机", "score" => 78.6),
    3 => array("tag" => "智能", "score" => 65.3),
    4 => array("tag" => "测试", "score" => 35.6),
);
*/

//mlog($_POST);

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

if (!isset($_POST['q']) || empty($_POST['q'])) {
    $query = "请输入查询词";
    $queryArray[] = $query;
} else {
    $query = $_POST['q'];
    $queryArray = ch2arr($query);
}

$result = [];
foreach ($queryArray as $key => $value) {
    $result[] = array(
        "tag" => $value,
        "score" => rand(1, 99),
    ); 
}

mlog($result);
echo json_encode($result);

