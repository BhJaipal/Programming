import os

with open(f"{os.getcwd()}/cli/aloo", "r") as f:
	content = f.read()

content = content.replace("$pwd$", os.getcwd())
with open(f"{os.getcwd()}/bin/aloo", "w") as f:
	f.write(content)
os.system("chmod +x bin/aloo")