from pynput import keyboard

output_file = "output.txt"

def on_press(key):
    with open(output_file, "a") as f:
        f.write(f"Pressed: {key}\n")

def on_release(key):
    if key == keyboard.Key.esc:
        return False

with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()
