<?php

fuction android_fileupload_services_resource(){
  $api = array(
	'create_message' => array(
  	'operations' => array(
    	'retrieve' => array(
      	'help' => 'Create Message.',
      	'file' => array(
        	'type' => 'inc',
        	'module' => 'android-fileupload',
        	'name' => 'android-fileupload',
      	),
		'callback' => 'create_message_services',
		'access callback' => 'services_access_menu',
		'access arguments append' => TRUE,
		'args' => array(
			array(
			  'name' => 'data',
			  'type' => 'array',
			  'description' => 'A valid data',
			  'source' => 'data',
			  'optional' => FALSE,
			),
		  ),
    	),
      	),
	),
  );

  return $api;
}

function create_message_services($data){
	$node = new StdClass();
	$node->type = 'messgae';
	$node->language = 'en';
	$node->title = $data['title'];
	node_save($node);
}