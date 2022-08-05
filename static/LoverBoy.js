
function SudokuGenerate() {
  var table = document.getElementById("grid");


  var rowLength = 9;
  let counter = 0;
  let totalhtml = ""

  for (var i = 0; i < rowLength; i ++) {
    let htmlBlah = `<tr class ="row">
      <td id =${counter} class ="cell"><input type="text" maxlength="1"></td>
      <td id =${counter + 1} class ="cell"><input type="text" maxlength="1"></td>
      <td id =${counter + 2} class ="cell"><input type="text" maxlength="1"></td>
      <td id =${counter + 3} class ="cell"><input type="text" maxlength="1"></td>
      <td id =${counter + 4} class ="cell"><input type="text" maxlength="1"></td>
      <td id =${counter + 5} class ="cell"><input type="text" maxlength="1"></td>
      <td id =${counter + 6} class ="cell"><input type="text" maxlength="1"></td>
      <td id =${counter + 7} class ="cell"><input type="text" maxlength="1"></td>
      <td id =${counter + 8} class ="cell"><input type="text" maxlength="1"></td>
        </tr>`
    var row = table.rows[i];
    counter += rowLength;
    totalhtml += htmlBlah;
  }

  table.innerHTML = totalhtml;
}

async function NaharLover(){
  var table = document.getElementById("grid")
  let generated_arr;
  await fetch("http://127.0.0.1:5000/logic", {
    method: "GET",
    headers: {Accept:"application/json","Content-Type":"application/json"}

  }).then(res => res.json())
  .then(data => generated_arr = data)
  console.log(generated_arr);

  let hidden_array;
  await fetch("http://127.0.0.1:5000/get_hidden_array", {
    method: "GET",
    headers: {Accept:"application/json", "Content-Type": "application/json"}
  }).then(res=> res.json())
  .then(data => hidden_array = data)

  console.log(hidden_array);
  for(let i = 0; i < 9; i++){
    for(let j = 0; j < 9; j++){
      
      if(hidden_array[i][j] == 1){
        let temp = i * 9 + j;
        let defined_cell = document.getElementById(temp.toString());
        //console.log(defined_cell);
        defined_cell.innerHTML = generated_arr[i][j].toString();
      }else{

      }       
      defined_cell.onchange = function () {
        val = this.value;
        console.log(val);
        if(val == generated_arr[i][j])
        {
          defined_cell.innerHTML = generated_arr[i][j].toString();
        }else{
          alert("not working");
        }
      };
    }
  }
}

async function main(){
  SudokuGenerate();
  await NaharLover();
}
