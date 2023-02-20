import discord
import openai
from discord.ext import commands
intents = discord.Intents.all()
bot = commands.Bot(command_prefix='*',intents=intents)

@bot.event
async def on_ready():
    print('BOT is working')

@bot.event
async def on_member_join(member):
    channel=bot.get_channel(1038816907161243738)
    await channel.send(f'{member}歡迎加入')

@bot.event
async def on_member_remove(member):
    channel=bot.get_channel(1038816907161243738)
    await channel.send(f'{member}再會')

@bot.event
async def on_message(msg):
    print(msg)
    response = requests.post(
        'https://api.openai.com/v1/images/generations',
        headers={'Authorization': f'Bearer {}'},
        json={
            "prompt": msg.content,
            "model": "image-alpha-001"
        }
    )
    generated_message = response.json()['data'][0]['url']
    await msg.channel.send(generated_message)

bot.run('MTAzNzY1MDQzMjc2MTI3NDQzMA.G0KQl6.CTHMSqoffyGDkvAqh8Hz33cnFrreJ0pHplXyU8')
#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