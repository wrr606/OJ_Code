import socket

def wake_on_lan(macaddress, broadcast="192.168.31.255", port=9):
    macaddress = macaddress.replace(":", "").replace("-", "").replace(".", "")

    data = b"FF" * 6 + (macaddress * 16).encode()
    magic_packet = bytes.fromhex(data.decode("utf-8"))

    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        sock.sendto(magic_packet, (broadcast, port))
    print(f"Magic Packet to {macaddress} via {broadcast}:{port}")

if __name__ == "__main__":
    target_mac = "04-92-26-C2-EC-C5"
    wake_on_lan(target_mac)