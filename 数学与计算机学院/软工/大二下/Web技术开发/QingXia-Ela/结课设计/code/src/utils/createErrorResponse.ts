export default function createErrorResponse(error: Error) {
  return new Response(JSON.stringify({
    status: 500,
    msg: error.message
  }), {
    status: 500
  })
}