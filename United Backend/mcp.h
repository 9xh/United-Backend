#pragma once

#include "httplib.h"
#include "json.hpp"

using namespace nlohmann;
using namespace httplib;

void StartMCP(Server &server)
{
	server.Get(R"(/fortnite/api/game/v2/profile/(.*)/client/(.*))", [](const Request& req, Response& res)
	{
			std::string accountID = req.matches[1];
			std::string command = req.matches[2];
	});
}

json common_public = R"()";

json GetCollection() { return common_public; }

json collections = R"()";

json GetCollection() { return collections; }
