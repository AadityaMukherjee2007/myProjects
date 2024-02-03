function addItem()
{
    const task = document.getElementById('todo').value;
    const taskElement = document.createElement('p');
    const taskInfo = document.createTextNode(task);
    taskElement.appendChild(taskInfo);

    const element = document.getElementById('tasks');
    element.appendChild(taskElement);
}
/*
const btn1 = document.getElementById('add_bt');
btn1.addEventListener('click', addItem);*/