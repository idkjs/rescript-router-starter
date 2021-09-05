open Test

@get external textContent: Dom.element => string = "textContent"

let elementContains = (~message=?, element: Dom.element, substring: string) =>
  assertion(
    ~message?,
    ~operator="elementContains",
    (textContent, substring) => {
      textContent->ReScriptJs__Js.String.includes(substring)
    },
    element->textContent,
    substring,
  )
