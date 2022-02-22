import subprocess

# Declare custom arguments
arg1 = "23"
arg2 = "test"

# Run cpp program as a subprocess
run_subprocess = subprocess.run(["./program", arg1, arg2], stdout=subprocess.PIPE, text=True)
# Capture output of stdout
subprocess_output = run_subprocess.stdout

print(subprocess_output)

# Process the output: split the received string on a specific character
output_data = subprocess_output.split(';')
# Extract the info that we want
whatever = output_data[0]

print(whatever)