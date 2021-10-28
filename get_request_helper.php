<?php

$_APP_requests = false;
$_APP_json_requests = false;

if (! function_exists('request')) {
    // Get all request from http body or search it by name
    function request($name = null) {
        global $_APP_requests;
        if ($_APP_requests === false) {
            parse_str(file_get_contents('php://input'), $_APP_requests);
        }
        if (is_null($_APP_requests)) {
            return null;
        }
        if ($name == null) {
            return $_APP_requests;
        }
        return isset($_APP_requests[$name]) ? $_APP_requests[$name] : null;
    }
}

if (! function_exists('json_request')) {
    // Get all request from json string http body or search it by name
    function json_request($name = null) {
        global $_APP_json_requests;
        if ($_APP_json_requests === false) {
            $_APP_json_requests = json_decode(file_get_contents('php://input'), true);
        }
        if (is_null($_APP_json_requests)) {
            return null;
        }
        if ($name == null) {
            return $_APP_json_requests;
        }
        return isset($_APP_json_requests[$name]) ? $_APP_json_requests[$name] : null;
    }
}

if (! function_exists('url_query')) {
    // Get all request from url query string or search it by name
    function url_query($name = null) {
        if ($name == null) {
            return $_GET;
        }
        return isset($_GET[$name]) ? $_GET[$name] : null;
    }
}

