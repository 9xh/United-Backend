#include <iostream>
#include "httplib.h"
#include "util.h"
#include "mcp.h"

using namespace httplib;

Server server;

int main()
{
	StartMCP(server);
	server.set_logger([](const Request& req, const Response& res)
	{
			std::string bruh = "[" + req.method + "] " + req.path;
			Logs::RainbowLog(bruh);
			//Logs::DebugLog("Req: " + req.method + " Path: " + req.path + " Body: " + req.body + " Res: " + res.body);
	});
	server.listen("127.0.0.1", PORT);
}