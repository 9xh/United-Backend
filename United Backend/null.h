#pragma once

#include "httplib.h"
#include "json.hpp"
#include "fortnite-game.h"
#include "timeline.h"

using namespace httplib;
using namespace nlohmann;

const char* j = "application/json";

Result GetData(Response& res, const char* web, const char* path)
{
	Client w(web);
	Result a = w.Get(path);
	return a;
}

void a(Response& res)
{
	res.status = 204;
}

void b(Response& res)
{
	res.set_content("[]", j);
}

void jsonn(Response& res, json jso)
{
	res.set_content(jso.dump(), j);
}

void StartNULL(Server& server)
{
	server.Get(R"(socialban/api/public/v1/(.*))", [](const Request& req, Response& res)
	{
			a(res);
	});
	server.Get(R"(/fortnite/api/game/v2/enabled_features)", [](const Request& req, Response& res)
	{
			b(res);
	});
	server.Get(R"(/fortnite/api/v2/versioncheck/(.*))", [](const Request& req, Response& res)
	{
			jsonn(res, R"({"type": "NO_UPDATE"})"_json);
	});
	server.Get(R"(/fortnite/api/versioncheck/(.*))", [](const Request& req, Response& res)
	{
			jsonn(res, R"({"type": "NO_UPDATE"})"_json);
	});
	server.Get(R"(/content/api/pages/fortnite-game)", [](const Request& req, Response& res)
	{
			jsonn(res, GetFnGame());
	});
	server.Get(R"(/waitingroom/api/waitingroom)", [](const Request& req, Response& res)
	{
			a(res);
	});
	server.Get(R"(/datarouter/api/v1/public/(.*))", [](const Request& req, Response& res)
	{
			a(res);
	});
	server.Get(R"(/)", [](const Request& req, Response& res)
	{
			res.set_content("United Backend lol", "text/plain");
	});
	server.Get(R"(/fortnite/api/calendar/v1/timeline)", [](const Request& req, Response& res)
	{
			//Client time("https://api.nitestats.com");
			//Result k = time.Get("/v1/epic/modes");
			jsonn(res, GetTimeline());
	});
}