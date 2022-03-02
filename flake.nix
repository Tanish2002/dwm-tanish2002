{
  description = "A flake for installing my dwm build";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-21.11";

  outputs = { self, nixpkgs, ... }: {
    defaultPackage.x86_64-linux =
      with import nixpkgs { system = "x86_64-linux"; };
      pkgs.dwm.overrideAttrs (o: { src = self; });
  };
}
