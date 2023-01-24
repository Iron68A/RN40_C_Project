console.log("test");

var port = process.env['PORT'] || 3000;

const Discord = require("discord.js");
const loadCommands = require("./Loader/loadCommands");
const loadEvents = require("./Loader/loadEvents");
const config = require("./config")

bot = new Discord.Client({intents : 3276799})


bot.commands = new Discord.Collection()
bot.color = "#0002E1";

//bot.login(process.env.token);
bot.login(config.token);

loadCommands(bot)
loadEvents(bot)








   
