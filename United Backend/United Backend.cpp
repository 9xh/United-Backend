#include <iostream>
#include "httplib.h"
#include "util.h"
#include "mcp.h"
#include "null.h"

using namespace httplib;

Server server;

int main()
{
	StartMCP(server);
	StartNULL(server);
	server.set_logger([](const Request& req, const Response& res)
	{
			Logs::RainbowLog(std::string("[" + req.method + "] " + req.path));
			//Logs::DebugLog("Req: " + req.method + " Path: " + req.path + " Body: " + req.body + " Res: " + res.body);
	});
	server.listen("127.0.0.1", PORT);
}