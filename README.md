# CUB3D
> Multiplayer cub3d (wolf clone)

Cub3D is a project make for the school 19.
However this version is an improvement over the original assigment as they didn't ask us to make a multiplayer version of this project.

The whole point of this project is to introduce the students to the raycasting method.

## Installation

OS X:

```sh
make
```

Windows & Linux:

``Not tested``

## Usage example

>Single Player :
```sh
./cub3d maps/good/<map> <username>
```

>Multi Player :

Both player ``MUST`` run the same map
```sh
./cub3d maps/good/<map>.cub <username> <your port> <partner port> <partner ip>
```

## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description - Azerty or Qwerty</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program (aka quit/exit)</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Make a step forward</td>
<td valign="top" align="center"><kbd>&nbsp;Z&nbsp;</kbd> or <kbd>&nbsp;W&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Make a step backward</td>
<td valign="top" align="center"><kbd>&nbsp;S&nbsp;</kbd> or <kbd>&nbsp;S&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Make a step to the left</td>
<td valign="top" align="center"><kbd>&nbsp;Q&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Make a step to the right</td>
<td valign="top" align="center"><kbd>&nbsp;D&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Rotate to the left</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Rotate to the right</td>
<td valign="top" align="center"><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Shot</td>
<td valign="top" align="center"><kbd>&nbsp;space&nbsp;</kbd></td>
</tr>
</tbody>
</table>

## Meta

Martin Andre – [@Martichouu](https://twitter.com/Martichouu) – martichou.andre@gmail.com


Distributed under the MIT license. See ``LICENSE`` for more information.

Thanks to Mbochet for the help on the multiplayer part.

## Contributing

1. Fork it (<https://github.com/martichou/cub3d>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request
