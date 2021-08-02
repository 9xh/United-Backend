#pragma once
#include "httplib.h"
using namespace httplib;

void StartMCP(Server &server)
{
	server.Get("", [](const Request& req, Response& res)
	{

	});
}