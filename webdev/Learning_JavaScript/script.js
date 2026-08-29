function action()
{
	document.getElementById("para").innerHTML = "Line changed!";
}

function calc()
{
	let x, y, z;
	x = parseInt(document.getElementById("a").value);
	y = parseInt(document.getElementById("b").value);
	op = document.getElementById("op").value;

	if (op == "+")
	{
		z = x + y;
	}
	else if (op == "-")
	{
		z = x - y;
	}
	else if (op == "*")
	{
		z = x * y;
	}
	else if (op == "/")
	{
		z = x / y;
	}
	else if (op == "^")
	{
		z = Math.pow(x, y);
	}
	else if (op == "%")
	{
		z = x % y;
	}
	else
	{
		window.alert("Error!");
	}

	document.getElementById("ans").value=z;
}