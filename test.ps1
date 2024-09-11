$arrayList = New-Object -TypeName System.Collections.ArrayList
Measure-Command -Expression { $arrayList.AddRange(@(0..50000)) }