Emotion.injectGlobal(`
html {
  padding: 0;
  margin: 0;
  height: -webkit-fill-available;
  font-family: sans-serif;
}
body {
  padding: 0;
  margin: 0;
  display: flex;
  flex-direction: column;
  min-height: 100vh;
  min-height: -webkit-fill-available;
}
#root {
  display: flex;
  flex-direction: column;
  flex-grow: 1
}`)
open ReScriptJs__Js
module App = {
  @react.component
  let make = () => {
    let url = Router.useUrl()

    React.useEffect1(() => {
      let () = ReScriptJs__Js.window["scrollTo"](. 0, 0)
      None
    }, [url.path])

    <>
      <Head
        defaultTitle="ReScript Form" titleTemplate="%s - ReScript Form"
      />
        <MainLayout>
      {switch (url.path) {
       | list{"login"} => <Form formType=FormTypes.Login />
       | list{"register"} => <Form formType=FormTypes.Register />
       | list{} => <Main />
        | _ => <ErrorPage text="Not found" />
       }}
    </MainLayout>
      <Footer />
    </>
  }
}

switch ReactDOM.querySelector("#root") {
| Some(root) => ReactDOM.render(<App />, root)
| None => Console.error("Missing #root element")
}
