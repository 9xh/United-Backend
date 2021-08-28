#pragma once

#include "httplib.h"
#include "json.hpp"

using namespace nlohmann;
using namespace httplib;

void StartMCP(Server &server)
{
	server.Get("", [](const Request& req, Response& res)
	{

	});
}

json common_public = R"()";

json GetCollection() { return common_public; }

json collections = R"()";

json GetCollection() { return collections; }
