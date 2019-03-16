from discord_webhook import DiscordWebhook
import subprocess

URL = ""

CONTENT = subprocess.check_output(["bentimes"])
DiscordWebhook(url=URL, content=CONTENT).execute()
