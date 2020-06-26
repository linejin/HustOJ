<?php
 $cache_time=10;
	$OJ_CACHE_SHARE=false;
	require_once('./include/cache_start.php');
    require_once('./include/db_info.inc.php');
	require_once('./include/setlang.php');
	$view_title= "Source Code";
   
require_once("./include/const.inc.php");
if (!isset($_GET['id'])){
	$view_errors= "No such code!\n";
	require("template/".$OJ_TEMPLATE."/error.php");
	exit(0);
}
$ok=false;
$id=intval($_GET['id']);
$sql="SELECT * FROM `solution` WHERE `solution_id`=?";
$result=pdo_query($sql,$id);
$row=$result[0];
$slanguage=$row['language'];
$sresult=$row['result'];
$stime=$row['time'];
$smemory=$row['memory'];
$sproblem_id=$row['problem_id'];
$view_user_id=$suser_id=$row['user_id'];
$contest_id=$row['contest_id'];



if(isset($OJ_EXAM_CONTEST_ID)){
	if($contest_id<$OJ_EXAM_CONTEST_ID&&!isset($_SESSION[$OJ_NAME.'_'.'source_browser'])){
	header("Content-type: text/html; charset=utf-8");
	 echo $MSG_SOURCE_NOT_ALLOWED_FOR_EXAM;
	 exit();
	}
}

if (isset($OJ_AUTO_SHARE)&&$OJ_AUTO_SHARE&&isset($_SESSION[$OJ_NAME.'_'.'user_id'])){
	$sql="SELECT 1 FROM solution where 
			result=4 and problem_id=$sproblem_id and user_id=?";
	$rrs=pdo_query($sql,$_SESSION[$OJ_NAME.'_'.'user_id']);
	$ok=(count($rrs)>0);
	
}

//check whether user has the right of view solutions of this problem
//echo "checking...";
if(isset($_SESSION[$OJ_NAME.'_'.'s'.$sproblem_id])){
	$ok=true;
//	echo "Yes";
}else{
	$sql="select count(1) from privilege where user_id=? and rightstr=?";
	$count=pdo_query($sql,$_SESSION[$OJ_NAME.'_'.'user_id'],"s".$sproblem_id);
	if($count&&$count[0][0]>0){
		$_SESSION[$OJ_NAME.'_'.'s'.$sproblem_id]=true;
		$ok=true;
	}else{
		//echo "not right";
	}

}
$view_source="No source code available!";
if (isset($_SESSION[$OJ_NAME.'_'.'user_id'])&&$row && $row['user_id']==$_SESSION[$OJ_NAME.'_'.'user_id']) $ok=true;
if (isset($_SESSION[$OJ_NAME.'_'.'source_browser'])) $ok=true;

		$sql="SELECT `source` FROM `source_code_user` WHERE `solution_id`=?";
		$result=pdo_query($sql,$id);
		 $row=$result[0];
		if($row)
			$view_source=$row['source'];
if(isset($_SESSION['administrator'])){
	echo "\tIP : $row->ip\n";
	echo "\tSubmission Time : $row->in_date\n";	

}
/////////////////////////Template
require("template/".$OJ_TEMPLATE."/showsource.php");
/////////////////////////Common foot
if(file_exists('./include/cache_end.php'))
	require_once('./include/cache_end.php');
?>
